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
int b[200010];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }

    int l = 1, r = n;
    while(l < r) {
        int m = l + r + 1 >> 1;

        int x = 0;
        for(int i=1; i<=n; i++) {
            if(a[i] + b[i] >= m-1 && b[i] >= x && a[i] >= m-x-1) x++;
        }

        if(x >= m) l = m;
        else r = m-1;
    }

    cout << l << "\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}