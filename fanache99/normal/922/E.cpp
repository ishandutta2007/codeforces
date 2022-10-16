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
#include <cassert>

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
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 1000;
const int MAXVAL = 10000;

int c[1 + MAXN];
long long dp[2][1 + MAXVAL], cost[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, sum = 0;
    long long w, b, x;
    scanf("%d%I64d%I64d%I64d", &n, &w, &b, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &cost[i]);
    int now = 1, before = 0;
    dp[now][0] = w;
    for (int i = 1; i <= c[1]; i++)
        if (cost[1] * i <= w)
            dp[now][i] = w - cost[1] * i;
        else
            dp[now][i] = -1;
    for (int i = c[1] + 1; i <= sum; i++)
        dp[now][i] = -1;
    int preffix = c[1];
    for (int i = 2; i <= n; i++) {
        swap(now, before);
        preffix += c[i];
        for (int j = preffix + 1; j <= sum; j++)
            dp[now][j] = -1;
        deque<int> Deque;
        for (int j = 0; j <= preffix; j++) {
            while (!Deque.empty() && Deque.front() < j - c[i])
                Deque.pop_front();
            if (dp[before][j] != -1) {
                while (!Deque.empty() && min(dp[before][Deque.back()] + x, w + b * Deque.back()) - cost[i] * (j - Deque.back()) <= min(dp[before][j] + x, w + b * j))
                    Deque.pop_back();
                Deque.push_back(j);
            }
            if (Deque.empty() || min(dp[before][Deque.front()] + x, w + b * Deque.front()) - cost[i] * (j - Deque.front()) < 0)
                dp[now][j] = -1;
            else
                dp[now][j] = min(dp[before][Deque.front()] + x, w + b * Deque.front()) - cost[i] * (j - Deque.front());
        }
    }
    for (int i = sum; i >= 0; i--)
        if (dp[now][i] != -1) {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}