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

double f[57][57][57],g[57][57][57];
double c[57][57];
int a[57],n,m;

int main()
{
    REP(i,57) c[i][0] = 1;
    for (int i = 1;i < 57;++i)
        for (int j = 1;j <= i;++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    cin >> n >> m;
    for (int i = 1;i <= m;++i)
        cin >> a[i];
    CLEAR(f);
    CLEAR(g);
    f[0][0][0] = 1;
    for (int i = 0;i < m;++i)
        for (int j = 0;j <= n;++j)
            for (int k = 0;k <= j;++k)
            {
                if (f[i][j][k]<=0) continue;
                for (int r = 0;r <= n;++r)
                    if (j+r<=n)
                        f[i+1][j+r][max(k,r/a[i+1]+(r%a[i+1]!=0))] += f[i][j][k] * c[n-j][r];
            }
    double ans = 0,down = 0;
    for (int i = 0;i <= n;++i)
    {
        ans += f[m][n][i] * i;
        down += f[m][n][i];
    }
    //cout << ans << " " << down << endl;
    printf("%.16f\n",ans/down);
    return 0;
}