#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const int inf = 1e8;

char a[1005][1005];
int d[1005][1005];
bool vis[1005][1005];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    pair<int,int> st, en;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'S')st = {i, j};
            if(a[i][j] == 'E')en = {i, j};
            vis[i][j] = false;
            d[i][j] = inf;
        }
    }
    queue<pair<int,int> > myq;
    myq.push(en);
    vis[en.first][en.second] = true;
    d[en.first][en.second] = 0;
    while(!myq.empty()){
        int x = myq.front().first;
        int y = myq.front().second;
        myq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m)continue;
            if(!vis[nx][ny] && a[nx][ny] != 'T'){
                vis[nx][ny] = true;
                d[nx][ny] = d[x][y] + 1;
                myq.push({nx, ny});
            }
        }
    }
    int md = d[st.first][st.second];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // cout<<d[i][j]<< " ";
            if(a[i][j] <= '9' && a[i][j] >= '0' && d[i][j] <= md){
                ans += a[i][j] - '0';
            }
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
}