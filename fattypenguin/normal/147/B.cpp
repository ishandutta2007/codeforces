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

int mat[301][301],rst[301][301],bas[301][301];
int pw[10][301][301];
int n;

const int inf = 1000000;

void mul(int a[301][301],int b[301][301])
{
    REP(i,n) REP(j,n) rst[i][j] = inf;
    REP(i,n) rst[i][i] = 0;
    REP(k,n) REP(i,n) REP(j,n) rst[i][j] = min(rst[i][j],a[i][k]+b[k][j]);
    REP(i,n) REP(j,n) a[i][j] = rst[i][j];
}
void out(int mat[301][301]);

void build()
{
    REP(i,n) REP(j,n) pw[0][i][j] = inf;
    REP(i,n) pw[0][i][i] = 0;
    REP(i,n) REP(j,n) pw[1][i][j] = bas[i][j];
    for (int i = 1;(1<<i)<=n;++i)
    {
        REP(j,n) REP(k,n) pw[i+1][j][k] = pw[i][j][k];
        mul(pw[i+1],pw[i]);
    //    out(pw[i]);
    }
}

void out(int mat[301][301])
{
    REP(i,n)
    {
        REP(j,n) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

bool yes(int w)
{
    REP(i,n) REP(j,n) mat[i][j] = inf;
    REP(i,n) mat[i][i] = 0;
  //  out(mat);
    for (int i = 0;w;w>>=1,++i)
    {
        if (w&1) mul(mat,pw[i+1]);
   //     out(mat);
    }
   // out(mat);
   // cout<<"--------------------\n";
    REP(i,n) if (mat[i][i]<0) { return true;}
    return false;
}

int answer()
{
    int l = 2,r = n;
    while (l < r)
    {
        int mid = (l+r)>>1;
        if (yes(mid))
            r = mid;
        else l = mid+1;
    }
    if (yes(l)) return l;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    CLEAR(bas);
    int m;
    cin>>n>>m;
    REP(i,n) REP(j,n) bas[i][j] = inf;
    REP(i,n) bas[i][i] = 0;
    REP(i,m)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        --a,--b;
        bas[a][b] = -c;
        bas[b][a] = -d;
    }
    build();
    cout<<answer()<<endl;
    return 0;
}