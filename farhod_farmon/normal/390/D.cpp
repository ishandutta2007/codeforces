#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 55;

using namespace std;

int n, m, k, g;
int d[N][N];

void fl(int x, int y)
{
    while(x <= n && y >= 1){
        g++;
        d[x][y] = g;
        x++;
        y--;
    }
}

bool cmp(pair < int, int > x, pair < int, int > y)
{
    return d[x.fi][x.se] > d[y.fi][y.se];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    int x = 1, y = 1;
    for(int i = 1; i < n + m; i++){
        fl(x, y);
        if(y == m)
            x++;
        else
            y++;
    }
    vector < pair < int, int > > v;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(d[i][j] <= k){
                v.pb({i, j});
                cnt += i + j - 1;
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    cout << cnt << endl;
    for(int i = 0; i < v.size(); i++){
        x = 1;
        y = 1;
        for(int j = 1; j < v[i].fi + v[i].se; j++){
            cout << "(" << x << "," << y << ")" << " \n"[j == v[i].fi + v[i].se - 1];
            if(y == v[i].se)
                x++;
            else
                y++;
        }
    }
}