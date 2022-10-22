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

int a[3000];

void solve() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    for(int i=n; i>=3; i-=2){
        for(int j=1; j<=i; j++) {
            if(a[j] == i) {
                if(j % 2 == 0) {
                    cout << "-1\n";
                    return;
                }

                reverse(a+1, a+j+1);
                if(j > 1) ans.eb(j);

                break;
            }
        }

        for(int j=1; j<=i; j++) {
            if(a[j] == i-1) {
                if(j % 2 == 1) {
                    cout << "-1\n";
                    return;
                }

                if(j-1 > 1) reverse(a+1, a+j);
                if(j-1 > 1) ans.eb(j-1);
                reverse(a+1, a+j+2);
                ans.eb(j+1);
                reverse(a+1, a+4);
                ans.eb(3);
                reverse(a+1, a+i+1);
                if(i > 1) ans.eb(i);

                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}