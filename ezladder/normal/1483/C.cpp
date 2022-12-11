#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

ll n;
ll h[300007];
ll b[300007];
ll dp[300007];


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // sum, b[i_i]
    vector<pair<ll, ll>> st; 

    set< pair<ll, pair<ll, ll> > > se;

    for (int i = 0; i < n; ++i) {
        ll cap = 0;
        if (i > 0) cap = dp[i - 1];
        while (st.size() > 0 && h[st.back().y] >= h[i]) {
            se.erase(mp(st.back().x + b[st.back().y], st.back()));
            cap = max(cap, st.back().x);
            st.pop_back();
        }
        st.push_back(mp(cap, i));
        se.insert(mp(cap + b[i], mp(cap, i)));
        dp[i] = prev(se.end())->x;
    }

    cout << dp[n - 1];
}