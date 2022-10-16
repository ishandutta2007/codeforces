
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>

using namespace std;

const int SIZE = 1 << 17;
int pointer = SIZE;
char buffer[SIZE];

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

const int MAXN = 100000;
const int MOD = 1000000007;

int preffix[1 + MAXN], dp[1 + MAXN], sum[1 + MAXN];
char s[1 + MAXN], t[1 + MAXN];

void Add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

void Subtract(int &x, int y) {
    x -= y;
    if (x < 0)
        x += MOD;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s\n%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int j = 2, i = 0; j <= m; j++) {
        while (i && t[i + 1] != t[j])
            i = preffix[i];
        if (t[i + 1] == t[j])
            i++;
        preffix[j] = i;
    }
    dp[0] = sum[0] = 1;
    for (int i = 1, j = 0, last = -1; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (j && t[j + 1] != s[i])
            j = preffix[j];
        if (t[j + 1] == s[i])
            j++;
        if (j == m) {
            j = preffix[j];
            last = i - m;
        }
        if (last != -1)
            Add(dp[i], sum[last]);
        sum[i] = sum[i - 1];
        Add(sum[i], dp[i]);
    }
    Subtract(dp[n], 1);
    printf("%d\n", dp[n]);
    return 0;
}