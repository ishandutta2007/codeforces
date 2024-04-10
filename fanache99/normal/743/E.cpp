#include <cstdio>
//#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const int MAXN = 1000;
const int SIGMA = 8;

int v[1 + MAXN];
int dp[1 + MAXN][1 << SIGMA];
bool seen[SIGMA];

int Try(int x, int n) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    deque<int> where[SIGMA];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << SIGMA); j++)
            dp[i][j] = dp[i - 1][j];
        where[v[i]].push_back(i);
        if (where[v[i]].size() < x)
            continue;
        int p = where[v[i]].front();
        if (where[v[i]].size() == x) {
            for (int j = 0; j < (1 << SIGMA); j++)
                if ((j & (1 << v[i])) && dp[where[v[i]].front() - 1][j ^ (1 << v[i])] != -1)
                    dp[i][j] = max(dp[i][j], dp[where[v[i]].front() - 1][j ^ (1 << v[i])] + x);
            continue;
        }
        for (int j = 0; j < (1 << SIGMA); j++)
            if ((j & (1 << v[i])) && dp[where[v[i]].front() - 1][j ^ (1 << v[i])] != -1)
                dp[i][j] = max(dp[i][j], dp[where[v[i]].front() - 1][j ^ (1 << v[i])] + x + 1);
        where[v[i]].pop_front();
        for (int j = 0; j < (1 << SIGMA); j++)
            if ((j & (1 << v[i])) && dp[where[v[i]].front() - 1][j ^ (1 << v[i])] != -1)
                dp[i][j] = max(dp[i][j], dp[where[v[i]].front() - 1][j ^ (1 << v[i])] + x);
    }
    return dp[n][(1 << SIGMA) - 1];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        v[i]--;
        seen[v[i]]++;
    }
    int left = 1, right = n, answer = 0;
    for (int i = 0; i < SIGMA; i++)
        if (seen[i])
            answer++;
    while (left <= right) {
        int middle = (left + right) / 2;
        int value = Try(middle, n);
        if (value != -1) {
            answer = value;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    printf("%d\n", answer);
    return 0;
}