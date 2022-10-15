#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;

const int MAXN = 512;

int g[2][MAXN][MAXN];

int d[2][MAXN][MAXN];

int main() 
{
    #ifdef ACMTUYO
        if (!freopen( "a.in" ,"r",stdin)) return 0;
    #endif
    int _sc = 0;
    int N,M;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        forn(i,N) forn(j,N) g[0][i][j] = 0;
        forn(i,M)
        {
            int x,y; _sc = scanf("%d%d", &x, &y);
            x--; y--;
            g[0][x][y] = 1;
            g[0][y][x] = 1;
        }
        forn(i,N) forn(j,N) g[1][i][j] = !g[0][i][j];
        forn(i,N) g[1][i][i] = 0;
        
        forn(k,2) forn(i,N) forn(j,N) d[k][i][j] = -1;
        
        int minDist = -1;
        queue<int> q;
        q.push(0); q.push(0); q.push(0);
        d[0][0][0] = 0;
        while (!q.empty())
        {
            int moves = q.front(); q.pop();
            int x[2];
            int &a = x[0] = q.front(); q.pop();
            int &b = x[1] = q.front(); q.pop();
            int D = d[moves][a][b];
            if (moves == 0 && a == N-1 && b == N-1)
            {
                minDist = D/2;
                break;
            }
            if (x[moves] == N-1)
            {
                if (d[!moves][a][b] < 0)
                {
                    d[!moves][a][b] = D+1;
                    q.push(!moves);
                    q.push(a);
                    q.push(b);
                }
            }
            else
            {
                forn(j, N)
                if (g[moves][x[moves]][j])
                {
                    int nPos[2] = {a,b};
                    nPos[moves] = j;
                    bool colision = moves == 1 && nPos[0] == nPos[1] && j != N-1;
                    if (!colision && d[!moves][nPos[0]][nPos[1]] < 0)
                    {
                        d[!moves][nPos[0]][nPos[1]] = D+1;
                        q.push(!moves);
                        q.push(nPos[0]);
                        q.push(nPos[1]);
                    }
                }
            }
        }
        printf("%d\n", minDist);
    }
    if (_sc) return 0;
    return 0;
}