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

int n, m;

char im[55][55];
int cnt = 0;

bool vis[55][55];

int dx[4] = {0, 0, -1, 1},
    dy[4] = {1, -1, 0, 0};

int all = 0;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    REP(k, 4)
    {
        int nx = x + dx[k],
            ny = y + dy[k];
        if (nx>=0&&nx<n&&ny>=0&&ny<m)
            if (im[nx][ny]=='#' && !vis[nx][ny])
                dfs(nx, ny);
    }
}

bool ok()
{
    REP(i, n) REP(j, m) vis[i][j] = false;

    bool chk = false;
    REP(i, n) REP(j, m) if (!vis[i][j] && im[i][j] == '#')
    {
        if (chk) return true;
        chk = 1;
        dfs(i, j);
    }
    return false;
}



int main()
{
    cin >> n >> m;
    REP(i, n) cin >> im[i];

    cnt = 0;
    REP(i, n) REP(j, m) cnt += (im[i][j] == '#');

    if (cnt == 1 || cnt == 2)
    {
        cout << -1 << endl;
        return 0;
    }

    int ans = 2;
  //  if (ok()) ans = 0;
    if (ans)
    {
        REP(i, n) REP(j, m) if (im[i][j]=='#')
        {
            im[i][j] = '.';
            if (ok())
            {
                ans = 1;
                break;
            }
            im[i][j] = '#';
        }
    }

    cout << ans << endl;


	return 0;
}