#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;

using namespace std;

int n, m;
int L[N], R[N];
int top[N];
int a[N];
vector < vector < char > > c;
vector < vector < bool > > used;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue < pair < int, int > > q;

void run(int x, int y)
{
        if(!used[x][y]){
                q.push({x, y});
                used[x][y] = true;
        }
        while(!q.empty()){
                x = q.front().fi;
                y = q.front().se;
                q.pop();
                for(int i = 0, nx, ny; i < 4; i++){
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || used[nx][ny]){
                                continue;
                        } else if(c[nx][ny] == '.' && i){
                                continue;
                        }
                        used[nx][ny] = true;
                        q.push({nx, ny});
                }
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        c.resize(n);
        used.resize(n);
        for(int i = 0; i < n; i++){
                c[i].resize(m);
                used[i].resize(m);

                for(int j = 0; j < m; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = 0; i < m; i++){
                int x;
                cin >> x;
                a[i] = top[i] = -1;
                for(int j = n - 1; j >= 0; j--){
                        if(c[j][i] == '#'){
                                x -= 1;
                                if(x == 0){
                                        a[i] = j;
                                }
                                top[i] = j;
                        }
                }
        }

        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        used[i][j] = 0;
                }
        }
        for(int i = 0, j = 0; i < m; i++){
                if(top[i] == -1){
                        continue;
                }
                run(top[i], i);

                j = max(j, i);
                while(j + 1 < m && (a[j + 1] == -1 || used[a[j + 1]][j + 1])){
                        j += 1;
                }
                R[i] = j;
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        used[i][j] = 0;
                }
        }
        for(int i = m - 1, j = m - 1; i >= 0; i--){
                if(top[i] == -1){
                        continue;
                }
                run(top[i], i);

                j = min(j, i);
                while(j - 1 >= 0 && (a[j - 1] == -1 || used[a[j - 1]][j - 1])){
                        j -= 1;
                }
                L[i] = j;
        }

        int res = 0;
        for(int i = 0; i < m; i++){
                if(top[i] == -1){
                        L[i] = m;
                }
                //cout << i << " " << L[i] << " " << R[i] << "\n";
        }
        for(int i = 0; i < m; i++){
                if(a[i] == -1){
                        continue;
                }
                res += 1;
                while(i + 1 < m && L[i + 1] <= i){
                        i += 1;
                }
                while(i + 1 < m && R[i] >= i + 1){
                        i += 1;
                }
        }
        cout << res << "\n";
}