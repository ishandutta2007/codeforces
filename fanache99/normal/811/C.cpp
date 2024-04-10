#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 5000;

int v[1 + MAXN], last[1 + MAXN], first[1 + MAXN], dp[1 + MAXN];
bool seen[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        last[v[i]] = i;
        if (!first[v[i]])
            first[v[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (i == last[v[i]]) {
            int j = i, now = 0, k = first[v[i]];
            bool ok = true;
            while (j >= k) {
                if (!seen[v[j]]) {
                    now ^= v[j];
                    k = min(k, first[v[j]]);
                    if (last[v[j]] > i) {
                        ok = false;
                        break;
                    }
                    seen[v[j]] = true;
                }
                j--;
            }
            if (ok)
                dp[i] = max(dp[i], dp[j] + now);
            for (int j = 1; j <= i; j++)
                seen[v[j]] = false;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}