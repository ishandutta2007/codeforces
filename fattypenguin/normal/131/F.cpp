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
#include <cassert>
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
typedef set<int>::iterator SI;

char mp[507][507];
int n,m,k;
int s[507],l[507];

bool ok(int x,int y)
{
    if (x+2<n)
        if (y-1>=0&&y+1<m)
        {
            if(mp[x][y]=='1'&&
               mp[x+1][y-1]=='1'&&mp[x+1][y]=='1'&&mp[x+1][y+1]=='1'&&mp[x+2][y]=='1')
                return true;
        }
    return false;
}

int has[500*500+10];

void inc(int x)
{
    ++x;
    while (x <= n*m+5)
    {
        ++has[x];
        x+=(x&-x);
    }
}


void dec(int x)
{
    ++x;
    while (x <= n*m+5)
    {
        --has[x];
        x+=(x&-x);
    }
}

int sum(int x)
{
    ++x;
    int ret=0;
    while (x)
    {
        ret+=has[x];
        x-=(x&-x);
    }
    return ret;
}

bool yes[507][507];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    REP(i,n) cin>>mp[i];
    REP(i,n) REP(j,m) yes[i][j]=ok(i,j);
    //CLEAR(has);
    long long ans=0;
    for (int i = 0;i < m;++i)
    {
        REP(j,n) l[j]=0;
        for (int j = i+2;j < m;++j)
        {
            for (int t = 0; t < n;++t)
                if (yes[t][j-1]) ++l[t];
            s[0]=l[0];
            for (int t=1;t < n;++t)
                s[t]=s[t-1]+l[t];
            int L=-1;
            for (int t=0;t<n-2;++t)
            {
                while (s[t]-s[L+1]>=k) ++L;
                int lft=(L==-1?0:s[L]);
                if (s[t]-lft>=k) ans += L+2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}