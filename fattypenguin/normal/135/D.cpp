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

char mp[1007][1007];
int n,m,ansi,black,white;
bool g[1007][1007],check;
int b[1007][1007];
int dx[8] = {1,-1,0,0,1,1,-1,-1},
    dy[8] = {0,0,1,-1,-1,1,-1,1};
int belong[1007][1007];

map<int,int> colors;

bool ok(int x,int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

void flood(int x,int y)
{
    if (mp[x][y]=='1') return;
    if (g[x][y]) return;
    g[x][y] = true;
    REP(i,8)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if (ok(nx,ny)) flood(nx,ny);
    }
}

void flood1(int x,int y)
{
    if (mp[x][y]=='0') return;
    if (b[x][y]) return;
    b[x][y] = black;
    REP(i,4)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if (ok(nx,ny)) flood1(nx,ny);
    }
}

int ans = 0;
int xx,yy;

void gao(int x,int y)
{
    if (mp[x][y]=='1') return;
    if (g[x][y]) return;
    g[x][y] = true;
    REP(i,8)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if (ok(nx,ny)) gao(nx,ny);
        if (ok(nx,ny) && mp[nx][ny]=='1')
        {
            colors[b[nx][ny]]=1;
            belong[nx][ny] = white;
            xx = nx,yy = ny;
        }
    }
}

bool bad;
int ts[1007][1007];

void test(int x,int y)
{
   // cout<<x<<y<<endl;
    if (belong[x][y]!=white) return;
    if (ts[x][y] == white) return;
    ts[x][y] = white;
    ++ansi;
    if (mp[x][y]=='0') bad = true;
    int nei = 0;
    REP(i,4)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if (ok(nx,ny))
        {
            test(nx,ny);
            if (belong[nx][ny] == white) ++nei;
        }
    }
    if (nei != 2) bad = true;
}

int main()
{
    scanf("%d%d",&n,&m);
    CLEAR(g); CLEAR(b); CLEAR(belong); CLEAR(ts);
    REP(i,n) scanf("%s",mp[i]);
    REP(i,m)
    {
        if (mp[0][i]=='0') flood(0,i);
        if (mp[n-1][i]=='0') flood(n-1,i);
    }
    REP(i,n)
    {
        if (mp[i][0]=='0') flood(i,0);
        if (mp[i][m-1]=='0') flood(i,m-1);
    }
    black = 0;
    REP(i,n) REP(j,m)
        if (!b[i][j] && mp[i][j]=='1')
        {
            ++black;
            flood1(i,j);
        }
    REP(i,n) REP(j,m)
        if (!g[i][j] && mp[i][j]=='0')
        {
            colors.clear();
            white++;
            gao(i,j);
    //        cout<<i<<j<<endl;
            if (colors.size()==1)
            {
                bad = false;
                ansi = 0;
                test(xx,yy);
                if (!bad) ans = max(ans,ansi);
            }
        }
    for (int i=0;i+1<n;++i)
        for (int j=0;j+1<m;++j)
        if (mp[i][j]=='1' && mp[i+1][j]=='1' && mp[i][j+1]=='1' && mp[i+1][j+1]=='1')
            ans=max(ans,4);
    cout<<ans<<endl;
}