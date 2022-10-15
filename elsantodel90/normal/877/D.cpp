#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

const int MAXN = 1024;
const int INF = 1000000000;

string v[MAXN];
int d[MAXN][MAXN];

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;
    cin >> N >> M >> K;
    forn(i,N)
        cin >> v[i];
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    forn(i,N)
    forn(j,M)
        d[i][j] = INF;
    queue<int> q;
    q.push(x1);
    q.push(y1);
    d[x1][y1] = 0;
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        if (x == x2 && y == y2)
        {
            cout << d[x][y] << "\n";
            return 0;
        }        
        int ndist = d[x][y] + 1;
        forn(dir, 4)
        forsn(steps, 1, K+1)
        {
            int nx = x + dx[dir] * steps;
            int ny = y + dy[dir] * steps;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || v[nx][ny] == '#' || d[nx][ny] <= d[x][y])
                break;
            if (ndist < d[nx][ny])
            {
                d[nx][ny] = ndist;
                q.push(nx);
                q.push(ny);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}