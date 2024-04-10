#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

double dp[100007][107];
int n;
int a[100007];
int cur[100007];

double mem[107];

double CC[122][122];

double C(int n, int m)
{
    if (m == 0 || m == n)
        return 1;
    if (n <= 101) return CC[n][m];

    double ret = 1;
    int j = 1;
    //C(n, i) = n! / i! / (n - i)!
    for (int i = n; i >= n - m + 1; --i, ++j)
        ret = ret * i / (double)j;
    return ret;
}

int main()
{
    for (int i = 0; i < 120; ++i)
    {
        CC[i][0] = CC[i][i] = 1;
        for (int j = 1; j < i; ++j)
            CC[i][j] = CC[i-1][j] + CC[i-1][j-1];
    }
    scanf("%d", &n);
    //REP(i, 100007) REP(j, 107) dp[i][j] = 2.0;
    double curr = 0;
    REP(i, n)
    {
        scanf("%d", &a[i]);
        cur[i] = a[i];
        dp[i][a[i]] = 1.0;
        if (!a[i]) ++curr;
    }

    int q, u, v, k;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%d", &u, &v, &k);
        --u, --v;

        for (int i = 0; i <= a[u]; ++i)
            mem[i] = 0;
        curr -= dp[u][0];
        for (int i = 0; i <= a[u] && i <= cur[u]; ++i)
        {
            double co = 1.0 / C(cur[u], k);
            for (int j = 0; j <= i && j <= k; ++j)
            {
                //prob = C[i][j] * C[cur[i]-i][k-j] / C[cur[i]][k];
                double prob = C(i, j) * co * C(cur[u] - i, k - j);
                mem[i-j] += dp[u][i] * prob;
            }
        }

        for (int i = 0; i <= a[u]; ++i)
            dp[u][i] = mem[i];
        curr += dp[u][0];

        cur[v] += k;
        cur[u] -= k;

        printf("%.10f\n", curr);
    }
	return 0;
}