#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m, can, k;
int a[2222];
int to[2222];
int b[2222];

int dp[1555][1555];

bool ok(int val){
    for (int i = 1; i <= n; i++){
        b[i] = b[i - 1] + (a[i] <= val);
        //cout << b[i] << ' ' << to[i] << endl;
    }

    for (int i = 0; i < 1555; i++) for (int j = 0; j < 1555; j++) dp[i][j] = -1;

    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++) for (int j = 0; j <= can; j++) if (dp[i][j] != -1){
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        if (to[i] > i){
            dp[to[i]][j + 1] = max(dp[to[i]][j + 1], dp[i][j] + b[to[i]] - b[i]);
        }
    }

    for (int i = 0; i <= n; i++) for (int j = 0; j <= can; j++) if (dp[i][j] >= k) return 1;
    return 0;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> can >> k;
    vector<int> d;
    to[0] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i], d.pb(a[i]), to[i] = -1;
    sort(all(d));
    for (int i = 0; i < m; i++){
        int w1, w2;
        cin >> w1 >> w2;
        to[w1 - 1] = max(to[w1 - 1], w2);
    }
    for (int i = 1; i <= n; i++) to[i] = max(to[i], to[i - 1]);
    int vl = -1, vr = d.size();
    while(vl + 1 < vr){
        int vm = (vl + vr) >> 1;
        if (ok(d[vm]))
            vr = vm;
        else
            vl = vm;
    }
    if (vr == d.size()) cout << -1; else cout << d[vr];
}