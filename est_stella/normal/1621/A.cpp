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

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        if((n+1)/2 < k) {
            cout << "-1\n";
            continue;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j && (i & 1) && i/2 < k) cout << 'R';
                else cout << '.';
            }
            cout << "\n";
        }
    }
}