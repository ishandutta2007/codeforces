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
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

ll f[21][12][12][4][2];

int main()
{
    int n,t;
    ios::sync_with_stdio(false);
    cin >> n >> t;
    CLEAR(f);
    REP(i,4) REP(j,4)
        if (i!=j)
            f[1][0][0][j][i>j] += 1;
    for (int i = 1;i < n-1;++i)
        for (int j = 0;j <= t;++j)
            for (int k = 0;k < t;++k)
                for (int r = 0;r < 4;++r)
                {
                        for (int s = 0;s < 4;++s)
                            if (r != s)
                            {
                                if (s > r)
                                {
                                    f[i+1][j][k][s][0] += f[i][j][k][r][0];
                                    f[i+1][j][k+1][s][0] += f[i][j][k][r][1];
                                }
                                else
                                {
                                    f[i+1][j][k][s][1] += f[i][j][k][r][1];
                                    f[i+1][j+1][k][s][1] += f[i][j][k][r][0];
                                }

                            }
                }
    ll ans = 0;
    REP(i,4) REP(j,2) ans += f[n-1][t][t-1][i][j];
    cout << ans << endl;
}