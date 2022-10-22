#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int i;
    ll ans = 0;
    while(i < n) {
        vector<ll> b;
        int j;
        for (j = i; j < n && s[j] == s[i]; j++) {
            b.push_back(a[j]);
        }
        sort(all(b));
        reverse(all(b));
        rep(l,0,min(sz(b), k)) {
            ans += b[l];
        }
        i = j;
    }
    cout << ans << endl;
}