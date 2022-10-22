#include <bits/stdc++.h>
#define DO_MOD
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
#ifdef DO_MOD
typedef long long Type;
#else
typedef long double Type;
#endif
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll nCr[5500][150];
const ll mod = (119 << 23) + 1, root = 3; // = 998244353

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

Type inv(Type a) {
#ifdef DO_MOD
    return modpow(a, mod-2);
#else
    return 1.0/a;
#endif
}

ll binom(ll n, ll k) {
    if (n == -1 && k == -1)
        return 1;
    if (k < 0 || k > n || n < 0)
        return 0;
    return nCr[n][k];
}

int main(){
    nCr[0][0] = 1;
    rep(i,1,5500)
        rep(j,0,150) {
            nCr[i][j] = nCr[i-1][j];
            if (j) {
                nCr[i][j] += nCr[i-1][j-1];
                nCr[i][j] %= mod;
            }
        }
	ios::sync_with_stdio(0);
    int p, s, r;
    cin >> p >> s >> r;
    Type succeeding = 0;
    Type total = 0;
    rep(a1,r,s+1) {
        total += binom(s+p-2-a1, p-2);
#ifdef DO_MOD
        total %= mod;
#endif
        Type states = 0;
        vector<ll> counted(p);
        rep(numSame,0,p) {
            if (s+p-numSame-2-(numSame+1)*a1 < -1)
                break;
            rep(numLargerOrEqual,0,p-numSame) {
                if (s+p-numSame-2-(numSame+1+numLargerOrEqual)*a1 < -1)
                    break;
                /*ll coeff = inv(k+1) - counted[k];
                rep(l,k,p) {
                    counted[l] += coeff * binom(l, k);
                }*/
                Type mul = (numLargerOrEqual%2?-1:1);
                Type t = mul * binom(p-1, numSame);
                t *= binom(p-1-numSame, numLargerOrEqual);
#ifdef DO_MOD
                t %= mod;
#endif
                /*if (s+p-numSame-2-(numSame+1+numLargerOrEqual)*a1 == -1 && numSame == p-1)
                    t *= 1;
                else {*/
                    t *= binom(s+p-numSame-2-(numSame+1+numLargerOrEqual)*a1, p-2-numSame);
                //}
#ifdef DO_MOD
                t %= mod;
#endif
                t *= inv(numSame+1);
                states += t;
#ifdef DO_MOD
                states %= mod;
#endif
                //t %= mod;
                /*states += coeff * binom(p-1, k) * binom(s+p-2-(k+1)*a1, p-2);
                states %= mod;*/
            }
        }
#ifdef DO_MOD
        if (states < 0)
            states += mod;
#endif
        succeeding += states;
#ifdef DO_MOD
        succeeding %= mod;
#endif
    }
    Type ans = succeeding * inv(total);
#ifdef DO_MOD
    ans %= mod;
#endif
    cout << ans << endl;
}