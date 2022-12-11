#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
int cnt[1111];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    ll ans = 0;
    for (int ost = 1; ost <= m; ost++){
        if (n - ost < 0) continue;
        cnt[ost % m] = (n - ost) / m + 1;
        //cout << ost << ' ' << cnt[ost] << endl;
    }
    for (int ost1 = 0; ost1 < m; ost1++) for (int ost2 = 0; ost2 < m; ost2++) if ((ost1 * ost1 + ost2 * ost2) % m == 0) ans += cnt[ost1] * (ll)cnt[ost2];
    cout << ans;
}