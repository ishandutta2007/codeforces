#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int cnt[200010][20];

int main() {
    fast;

    for(int i=1; i<=200000; i++) {
        for(int j=0; j<20; j++) {
            cnt[i][j] = cnt[i-1][j];
            if(i & (1<<j)) cnt[i][j]++; 
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;

        int mx = 0;
        for(int i=0; i<20; i++) {
            mx = max(mx, cnt[r][i] - cnt[l-1][i]);
        }
        cout << r - l + 1 - mx << "\n";
    }
}