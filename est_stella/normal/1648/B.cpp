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

int n, c;
int a[2000010];

void solve() {
    cin >> n >> c;

    for(int i=1; i<=2*c; i++) a[i] = 0;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    for(int i=1; i<=2*c; i++) a[i] += a[i-1];

    for(int i=1; i<=c; i++) {
        if(a[i] > a[i-1]) {
            for(int j=1; j*i<=c; j++) {
                if(a[j] == a[j-1] && a[j*i+i-1] > a[j*i-1]) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    cout << "Yes\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}