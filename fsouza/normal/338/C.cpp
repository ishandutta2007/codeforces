#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

map<lint, int> memo;
lint v[8];
int dp[8][1<<8];

lint nfactor(lint v)
{
    map<lint, int>::iterator it = memo.find(v);
    if (it != memo.end()) return it -> second;

    if ((v&1) == 0)
        return memo[v] = 1 + nfactor(v/2);
    
    for (lint x = 3; x*x <= v; x += 2)
        if (v%x == 0)
            return memo[v] = 1 + nfactor(v/x);

    if (v > 1)
        return memo[v] = 1;
    return memo[v] = 0; 
}

int main(int argc, char ** argv)
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v+n);

    for (int i = 0; i < n; i++)
        for (int s = 0; s < (1<<n); s++)
            dp[i][s] = INF;

    dp[0][1<<0] = ((nfactor(v[0]) == 1) ? 1 : (1 + nfactor(v[0])));
    for (int i = 1; i < n; i++) {
        for (int s = 0; s < (1<<i); s++) {
            lint remain = v[i];
            int err = 0;

            for (int j = 0; j < i; j++)
                if (s & (1<<j)) {
                    if (remain%v[j]) {
                        err = 1;
                        break;
                    }
                    remain /= v[j];
                }

            if (err)
                continue;

            int nused = __builtin_popcount(s);
            int nf = nfactor(remain);

            for (int s2 = 0; s2 < (1<<i); s2++) {
                if ((s2&s) != s) continue;

                int extra;

                if (nused == 0) {
                    if (nf == 1)
                        extra = 1;
                    else
                        extra = nf+1;
                } else {
                    extra = nf+1;
                }


                dp[i][(s2^s)|(1<<i)] = min(dp[i][(s2^s)|(1<<i)], dp[i-1][s2] + extra);
            }
        }
    }

    int result = INF;

    for (int s = 0; s < (1<<n); s++) {
        int nexposed = __builtin_popcount(s);
        result = min(result, dp[n-1][s] + (nexposed > 1));
    }

    cout << result << endl;

    return 0;
}