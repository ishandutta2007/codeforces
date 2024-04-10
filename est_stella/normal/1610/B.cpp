#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n;
int a[200010];

bool chk(int x) {
    int idx = n;
    for(int i=1; i<=n; i++) {
        if(a[i] == x) continue;
        while(a[idx] == x) idx--;

        if(a[i] != a[idx]) return false;
        idx--;
    }

    return true;
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    int x = 0, y = 0;
    for(int i=1; i<=n; i++) {
        if(a[i] != a[n+1-i]) {
            x = a[i];
            y = a[n+1-i];
            break;
        }
    }

    if(chk(x) || chk(y)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}