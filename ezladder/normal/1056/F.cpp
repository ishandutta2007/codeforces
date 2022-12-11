#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
db C, T;
pair<int, int> a[111];
db dp[2][107][1017];

void up(db &a, db b){
    if (a < 0) a = b;
    else a = min(a, b);
}

db step[111];

void solve(){
    cin >> n >> C >> T;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < 107; i++) for (int j = 0; j < 1017; j++) dp[0][i][j] = dp[1][i][j] = -1;
    dp[0][0][0] = 0;
    step[0] = (db)10 / 9;
    for (int i = 1; i < 111; i++) step[i] = step[i - 1] * 10 / (db)9;
    for (int i = 0; i < n; i++){
        for (int s = 0; s <= i + 1; s++) for (int j = 0; j <= 10 * (i + 1); j++) if (!(dp[0][s][j] < 0)){
            //cout << "===" << ' ' << dp[0][s][j] << endl;
            up(dp[1][s][j], dp[0][s][j]);
            up(dp[1][s + 1][j + a[i].y], dp[0][s][j] + (db)a[i].x * step[s]);
            //cout << dp[1][s + 1][j + a[i].y] << ' ' << (db)a[i].x * step[s] << ' ' << a[i].x << ' ' << step[0] << endl;
        }  
        for (int s = 0; s <= n; s++) for (int j = 0; j < 1007; j++) dp[0][s][j] = dp[1][s][j], dp[1][s][j] = -1;
    }
    int ans = 0;
    for (int now = 0; now < 1017; now++) for (int d = 0; d <= n; d++) if (dp[0][d][now] != -1){
        db ti = dp[0][d][now];
        db pos = max((db)0, (sqrt(C * ti) - 1) / C);
        //cout << d << ' ' << now << ' ' << ti << ' ' << C << ' ' << pos << endl;
        if ((pos + ti / (1 + C * pos) + 10 * d) <= T) ans = max(ans, now);
    }
    cout << ans << "\n";
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}