#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1005;
const ll mod = 1e9+7;

int grid[ms][ms];
int speed[10];
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int ans[10];
queue<pair<int, int>> q[10];
pair<int, int> curRound[ms][ms];

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++) cin >> speed[i];
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.') grid[i][j] = 0;
            else if(s[j] == '#') grid[i][j] = -1;
            else {
                grid[i][j] = s[j] - '0';
                q[s[j] - '0'].emplace(i, j);
                ans[s[j]-'0']++;
            }
        }
    }
    int empt = 0;
    for(int i = 1; i <= p; i++) if(q[i].empty()) empt++;
    int rnd = 0;
    while(empt < p) {
        rnd++;
        // cout << rnd << endl;
        for(int i = 1; i <= p; i++) {
            if(q[i].empty()) continue;
            while(!q[i].empty()) {
                int x = q[i].front().first, y = q[i].front().second;
                // cout << i << " COMECANDO EM: " << x << " " << y << " " << curRound[x][y].first << ' ' << curRound[x][y].second << endl;
                // cout << rnd << ' ' << speed[i] << endl;
                if(curRound[x][y] == pair<int, int>(rnd, speed[i])) break;
                // cout << "VAMOS LA" << endl;
                q[i].pop();
                int dist = curRound[x][y].first != rnd ? 0 : curRound[x][y].second;
                // cout << dist << " senhor" << endl;
                for(int mv = 0; mv < 4; mv++) {
                    int nx = x + mx[mv];
                    int ny = y + my[mv];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    // cout << nx <<  ' ' << ny << " meu movimento " << grid[nx][ny] << endl;
                    if(grid[nx][ny] == 0) {
                        grid[nx][ny] = i;
                        curRound[nx][ny] = {rnd, dist+1};
                        q[i].emplace(nx, ny);
                        ans[i]++;
                        // cout << i << " PINTEI o " << nx << ' ' << ny << endl;
                    }
                }
                // cout << "fim de " << x << ' ' << y << endl;
                // cout << "agora que jogou vavi ser :: " << endl;
                // for(int gap = 0; gap < n; gap++) {
                //     for(int gap2 = 0; gap2 < m; gap2++) {
                //         cout << 
                //     }
                //     cout << endl;
                // }
            }
            // cout << rnd << ' ' << i << " = " << ans[i] << endl;
            if(q[i].empty()) empt++;
        }
    }
    for(int i = 1; i <= p; i++) cout << ans[i] << ' ';
    cout << endl;
}