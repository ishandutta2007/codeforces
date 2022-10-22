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
int a[111];
int b[111];

void solve() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n);

    for(int i=0; i<n; i++) {
        if(a[i] != b[i] && a[i] != b[i]-1) {
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
    while(t--) {
        solve();
    }
}