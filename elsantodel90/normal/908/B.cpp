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
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;

const int MAX = 64;

string maze[MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("b.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin >> n >> m)
    {
        int sx = -1, sy = -1;
        int ex = -1, ey = -1;
        forn(i,n)
        {
            cin >> maze[i];
            assert(m == int(maze[i].size()));
            forn(j, maze[i].size())
            if (maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
                maze[i][j] = '.';
            }
            else if (maze[i][j] == 'E')
            {
                ex = i;
                ey = j;
                maze[i][j] = '.';
            }
        }
        assert(sx >= 0);
        assert(sy >= 0);
        assert(ex >= 0);
        assert(ey >= 0);
        string orders;
        cin >> orders;
        int mapping[4];
        forn(dir,4)
            mapping[dir] = dir;
        int total = 0;
        do
        {
            int x = sx, y = sy;
            #define llegamos (x == ex && y == ey)
            int nextOrder = 0;
            while (!llegamos)
            {
                if (nextOrder >= int(orders.size()))
                    break;
                int dir = mapping[orders[nextOrder++] - '0'];
                x += dx[dir];
                y += dy[dir];
                if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == '#')
                    break;
            }
            total += llegamos;
        } while (next_permutation(mapping,mapping+4));
        cout << total << endl;
    }
    return 0;
}