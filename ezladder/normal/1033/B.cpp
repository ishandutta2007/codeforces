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

int n;
int x[3], y[3];

bool can(int xx, int yy){
    if (xx < 0 || yy < 0 || xx >= n || yy >= n) return 0;
    if (xx == x[0] || yy == y[0]) return 0;
    int dx = abs(xx - x[0]);
    int dy = abs(yy - y[0]);
    if (dx == dy) return 0;
    return 1;
}

bool was[1007][1007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        ll w1, w2;
        cin >> w1 >> w2;
        if (abs(w1 - w2) != 1){
            cout << "NO\n";
            continue;
        }
        int f = 0;
        ll val = w1 + w2;
        for (ll i = 2; i * i <= val; i++) if (val % i == 0){
            f = 1;
            break;
        }
        if (f) cout << "NO\n"; else cout << "YES\n";
    }
    exit(0);
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    vector<pair<int, int> > t;
    t.pb(mp(x[1], y[1]));
    int uk = 0;
    was[x[1]][y[1]] = 1;
    while(uk < t.size()){
        auto now = t[uk++];
        if (now == mp(x[2], y[2])) cout << "YES", exit(0);
        for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (!(dx == 0 && dy == 0)){
            int nx = now.x + dx, ny = now.y + dy;
            if (can(nx, ny) && !was[nx][ny]){
                was[nx][ny] = 1;
                t.pb(mp(nx, ny));
            }
        }
    }

    cout << "NO";
}