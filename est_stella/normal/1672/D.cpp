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

int n;
vector<int> a, b;
int cnt[200010];

void solve() {
    cin >> n;

    a.resize(n);
    b.resize(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) cnt[i] = 0;

    while(a.size()) {
        int x = a.back();
        while(a.size() && a.back() == x) a.pop_back(), cnt[x]--;
        while(b.size() && b.back() == x) b.pop_back(), cnt[x]++;

        if(cnt[x] < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) solve();
}