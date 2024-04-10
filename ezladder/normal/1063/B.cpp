#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
int sx, sy;
int k1, k2;
char a[2002][2002];
pair<int, int> dp[2002][2002];
bool was[2002][2002];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> sx >> sy >> k1 >> k2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    sx--; sy--;
    was[sx][sy] = 1;
    deque<pair<int, int> > t;
    int uk = 0;
    t.pb(mp(sx, sy));
    while(t.size()){
        auto now = t.front();
        t.pop_front();
        //cout << now.x + 1 << ' ' << now.y + 1 << endl;
        for (int it = 0; it < 4; it++){
            int nx = now.x + dx[it];
            int ny = now.y + dy[it];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == '.'){
                if (it < 2){    
                    if (!was[nx][ny]){
                        was[nx][ny] = 1;
                        dp[nx][ny] = dp[now.x][now.y];
                        t.push_front(mp(nx, ny));
                    }
                } else {    
                    if (!was[nx][ny]){
                        was[nx][ny] = 1;
                        auto gg = dp[now.x][now.y];
                        if (it == 2) gg.x++;
                        if (it == 3) gg.y++;
                        dp[nx][ny] = gg;
                        t.push_back(mp(nx, ny));
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (was[i][j] && dp[i][j].x <= k1 && dp[i][j].y <= k2) ans++;
    cout << ans;
}