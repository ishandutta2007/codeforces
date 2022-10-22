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
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9+7;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;

    string st;
    int ans = 0;
    for(auto i : s) {
        if(i == ')' && st.size() && st.back() == ')') {
            st.pop_back();
            st.pop_back();
            st += i;
            ans++;
        }
        st += i;
    }

    cout << ans + 1 << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}