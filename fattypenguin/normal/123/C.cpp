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

char ans[107][107];
unsigned long long f[207][107];
int res[207];
int n,m;
unsigned long long k;
vector<pair<int,PII> > cor;

const ULL infi = 1200000000000000000ull;

long long calc()
{
    CLEAR(f);
    f[0][1] = 1;
    for (int i = 1;i < n+m-1;++i)
        for (int j = 0;j <= min(i+1,(n+m)/2);++j)
        {
            if (j) f[i][j] = f[i-1][j-1];
            if (res[i]==0)
                f[i][j] += f[i-1][j+1];
            if (res[i]==-1)
                f[i][j] = f[i-1][j+1];
            if (f[i][j] > infi) f[i][j] = infi;
        }
    return f[n+m-2][0];
}

int main()
{
    cin>>n>>m>>k;
    REP(i,n) REP(j,m)
    {
        int c;
        cin>>c;
        cor.PB(MP(c,MP(i,j)));
    }
    SORT(cor);
    CLEAR(ans);
    CLEAR(res);
    REP(i,n*m)
        if (ans[cor[i].second.first][cor[i].second.second] == 0)
        {
            int x = cor[i].second.first,
                y = cor[i].second.second;
            res[x+y] = 1;
            long long step = calc();
          //  cout<<step<<endl;
            if (k > step)
            {
                k -= step;
                res[x+y] = -1;
            }
            for (int i = 0;i <= x+y;++i)
                if (i < n && x+y-i < m)
                    if (res[x+y]==1)
                        ans[i][x+y-i]='(';
                    else ans[i][x+y-i]=')';
        }
    REP(i,n) cout<<ans[i]<<endl;
    return 0;
}