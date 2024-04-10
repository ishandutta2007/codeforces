#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
vector < vector < int > > d;
vector < vector < int > > f;
vector < vector < char > > c;

int nx, ny;
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {-1, 0, 1, 1, 0, -1, 1, -1};

bool good(int x, int y)
{
        for(int i = 0; i < 8; i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                        return true;
                }
                if(c[nx][ny] != 'X'){
                        return true;
                }
        }
        return false;
}

queue < pair < int, int > > q;

bool can(int k)
{
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(d[i][j] >= k){
                                f[i][j] = k;
                                q.push({i, j});
                        } else{
                                f[i][j] = -1;
                        }
                }
        }
        int x, y, nx, ny;
        while(!q.empty()){
                x = q.front().fi;
                y = q.front().se;
                q.pop();
                if(f[x][y] == 0){
                        continue;
                }
                for(int i = 0; i < 8; i++){
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                                continue;
                        }
                        if(f[nx][ny] == -1){
                                f[nx][ny] = f[x][y] - 1;
                                q.push({nx, ny});
                        }
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(f[i][j] != -1 && c[i][j] == '.'){
                                return false;
                        } else if(f[i][j] == -1 && c[i][j] == 'X'){
                                return false;
                        }
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        d.resize(n);
        c.resize(n);
        f.resize(n);
        for(int i = 0; i < n; i++){
                d[i].resize(m);
                c[i].resize(m);
                f[i].resize(m);
                for(int j = 0; j < m; j++){
                        cin >> c[i][j];
                        if(c[i][j] == 'X'){
                                d[i][j] = -1;
                        } else{
                                d[i][j] = -2;
                        }
                }
        }
        queue < pair < int, int > > q;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(c[i][j] == 'X' && good(i, j)){
                                d[i][j] = 0;
                                q.push({i, j});
                        }
                }
        }
        while(!q.empty()){
                int x = q.front().fi, y = q.front().se;
                q.pop();
                for(int i = 0; i < 8; i++){
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                                continue;
                        }
                        if(d[nx][ny] == -1){
                                d[nx][ny] = d[x][y] + 1;
                                q.push({nx, ny});
                        }
                }
        }
        int l = 0, r = min(n, m);
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        cout << l << "\n";
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(d[i][j] >= l){
                                cout << 'X';
                        } else{
                                cout << '.';
                        }
                }
                cout << '\n';
        }
}