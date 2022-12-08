#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

const ll mod = 998244353; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    const int M=201;
    vector<Mod> dp1(M,0), dp2(M,0), dp3(M,0), dp4(M,0);
    dp2[0] = 1;
    rep(i,0,n) {
        Mod acc = 0;
        rep(j,0,M) {
            dp3[j] = acc;
            acc = acc + dp1[j] + dp2[j];
        }
        acc = 0;
        for(int j=M-1; j>0; --j) {
            acc = acc + dp2[j];
            dp4[j] = acc+dp1[j];
        }
        dp4[0]=0;
        int a;
        cin >> a;
        if(a!=-1) {
            rep(j,1,M) if(j!=a) {
                dp3[j] = dp4[j] = 0;
            }
        }
        swap(dp1,dp3);
        swap(dp2,dp4);
    }
    Mod sum = 0;
    rep(j,0,M) sum = sum + dp2[j];
    cout << sum.x << endl;
}