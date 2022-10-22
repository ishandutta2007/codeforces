#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int query(int w) {
    cout << "? " << w << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    int n;
    cin >> n;

    int l = 1, r = 3000 * n;
    while(l < r) {
        int m = l + r >> 1;
        if(query(m) == 1) r = m;
        else l = m+1;
    }

    int ans = l;
    for(int i=1; i<=n; i++) {
        int x = query(l/i);
        if(x) ans = min(l/i * x, ans);
    }

    cout << "! " << ans << endl;
}