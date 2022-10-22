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
typedef bitset<500000> Bs;

Bs b;
ll n, k;

Bs getBitset(const string& s) {
    Bs ret;
    ret.reset();
    rep(i,0,n) {
        if (s[i] == 'b')
            ret.set(i);
    }
    return ret;
}

ll getPrefixLength(const Bs& s, const Bs& t) {
    rep(i,0,n)
        if (s.test(i) != t.test(i))
            return i;
    return n;
}

void print(Bs s) {
    rep(i,0,n) {
        cout << s.test(i);
    }
    cout << endl;
}

bool greaterThan(const Bs& s, const Bs& t) {
    rep(i,0,n) {
        if (s.test(i) < t.test(i))
            return 0;
        if (s.test(i) > t.test(i))
            return 1;
    }
    return 0;
}

int main(){
	ios::sync_with_stdio(0);
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    ll ans = n;
    while (n && s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
        --n;
    }
    reverse(all(s));
    reverse(all(t));
    int ind = 0;
    --k;
    auto sb = getBitset(s);
    auto tb = getBitset(t);
    //print(sb);
    //print(tb);
    while (k && ind < n) {
        //cerr << ind << " " << k << endl;
        b = sb;
        ll i;
        for (i = n-1; i > ind; i--) {
            b.reset(i);
        }
        while (k) {
            for (i = ind; i >= 0; i--) {
                b.flip(i);
                if (b.test(i))
                    break;
            }
            if (i < 0)
                break;
            if (greaterThan(b, tb))
                break;
            if (i == ind) {
                //print(b);
                //cout << "Add " << n-i << endl;
                ans += n-i;
                --k;
                for (ll l = i-1; l >= 0; --l) {
                    Bs c = b;
                    ll j;
                    for (j = l; j >= 0; --j) {
                        c.flip(j);
                        if (c.test(j))
                            break;
                    }
                    if (j < 0 || greaterThan(c, tb))
                        break;
                    //print(c);
                    ll num = min(k, (1LL<<(ind-l-1)));
                    //cout << "Superadd " << num*(n-i) << endl;
                    ans += num*(n-i);
                    k -= num;
                    b = c;
                }
            }
        }
        ++ind;
    }
    cout << ans << endl;
}