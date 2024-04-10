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

string s, t;

void solve() {
    cin >> s >> t;

    for(int i=0; i<s.size(); i++) {
        for(int j=i; j<s.size(); j++) {
            string w;
            for(int k=i; k<=j; k++) w += s[k];
            for(int k=j-1; k>=0 && w.size() < t.size(); k--) w += s[k];

            if(w == t) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }   
}