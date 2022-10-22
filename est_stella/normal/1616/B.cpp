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

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;

    bool flag = false;
    for(int i=1; i<n; i++) {
        if(s[i-1] < s[i]) {
            for(int j=0; j<i; j++) cout << s[j];
            for(int j=i-1; j>=0; j--) cout << s[j];
            cout << "\n";
            return;
        }

        if(s[i-1] == s[i] && i == 1) {
            for(int j=0; j<i; j++) cout << s[j];
            for(int j=i-1; j>=0; j--) cout << s[j];
            cout << "\n";
            return;
        }
    }

    for(int j=0; j<n; j++) cout << s[j];
    for(int j=n-1; j>=0; j--) cout << s[j];
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