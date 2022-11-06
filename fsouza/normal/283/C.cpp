#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 300
#define MAXS 100000

typedef long long lint;

using namespace std;

const lint mod = 1000000007LL;

int dp[2][MAXS+1];

int solve(vector<lint>& A, lint sum)
{
    if (sum < 0) return 0;
    int n = A.size();

    memset(dp[n&1], 0, sizeof(dp[n&1]));
    dp[n&1][0] = 1;

    for (int i = n-1; i >= 0; i--) {
        for (int v = 0; (lint)v <= sum; v++) {
            dp[i&1][v] = dp[(i+1)&1][v];
            if ((lint)v >= A[i]) {
                dp[i&1][v] = (dp[i&1][v] + dp[i&1][v-A[i]]);
                if (dp[i&1][v] >= mod)
                    dp[i&1][v] -= mod;
            }
        }
    }

    return dp[0][sum];
}

int main()
{
    int n, nq, _sum;

    scanf("%d %d %d", &n, &nq, &_sum);
    lint sum = _sum;
    
    vector <lint> A(n);
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        A[i] = v;
    }

    vector <int> parent(n, -1), child(n, -1);

    for (int i = 0; i < nq; i++) {
        int b, c;
        scanf("%d %d", &b, &c);
        b--, c--;
        child[b] = c;
        parent[c] = b;
    }
    
    vector <bool> ok(n, false);

    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            vector <int> path;
            for (int j = i; j != -1; j = child[j]) {
                path.push_back(j);
                ok[j] = true;
            }

            for (int k = 1; k < (int)path.size(); k++) {
                A[path[k]] += A[path[k-1]];
            }
            
            for (int k = 0; k+1 < (int)path.size(); k++)
                sum -= A[path[k]];
        }
    }

    for (int i = 0; i < n; i++)
        if (!ok[i]) {
            printf("0\n");
            return 0;
        }

    printf("%d\n", solve(A, sum));

    return 0;
}