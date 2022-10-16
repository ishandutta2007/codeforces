#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

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

char s[1 + MAXN];
int sum[1 + MAXN];
int subtract[2][1 + MAXN], bad[2];
pair<int, int> dp[1 + MAXN + 1];
int last[2][2];

pair<int, int> operator + (pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d\n%s%d", &n, s + 1, &m);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        if (s[i] == '?')
            sum[i]++;
    }
    last[0][0] = last[0][1] = last[1][0] = last[1][1] = n + 1;
    for (int i = n; i >= 1; i--) {
        dp[i] = dp[i + 1];
        if (s[i] != 'b') {
            int j = min(last[(i + 1) % 2][0], last[i % 2][1]);
            if (j - i >= m)
                dp[i] = max(dp[i], dp[i + m] + make_pair(1, -(sum[i + m - 1] - sum[i - 1])));
        }
        if (s[i] == 'a')
            last[i % 2][0] = i;
        if (s[i] == 'b')
            last[i % 2][1] = i;
    }
    printf("%d\n", -dp[1].second);
    return 0;
}