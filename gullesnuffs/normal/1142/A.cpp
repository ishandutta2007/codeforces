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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main(){
	ios::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll a, b;
    cin >> a >> b;
    ll x = 1e18;
    ll y = 0;
    rep(i,0,2) {
        rep(j,0,2) {
            ll A = i?a:-a;
            ll B = j?b:-b;
            ll s = i;
            rep(r,0,n) {
                ll l = B-A+r*k;
                l %= (n*k);
                if (l <= 0)
                    l += (n*k);
                ll times = n*k/gcd(l, n*k);
                x = min(x, times);
                y = max(y, times);
            }
        }
    }
    cout << x << " " << y << endl;
}