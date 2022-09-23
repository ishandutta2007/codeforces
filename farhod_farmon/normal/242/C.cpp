#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

map < pair < int, int >, bool > used;
map < pair < int, int >, int > d;
int n;

void bfs(int x, int y)
{
    queue < pair < int, int > > q;
    q.push({x, y});
    d[{x, y}] = 0;
    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        q.pop();
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0)
                    continue;
                int nx = x + i,
                    ny = y + j;
                if(used.find({nx, ny}) == used.end())
                    continue;
                if(d.find({nx, ny}) != d.end())
                    continue;
                d[{nx, ny}] = d[{x, y}] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, l, r;
        cin >> x >> l >> r;
        for(int j = l; j <= r; j++)
            used[{x, j}] = true;
    }
    bfs(x0, y0);
    if(d.find({x1, y1}) != d.end())
        cout << d[{x1, y1}];
    else
        cout << -1 << endl;
}