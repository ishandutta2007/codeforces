#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;

struct T {
    int t[2][2];
    T operator * (const T & other) const {
        T nowy;
        REP(a,2)REP(b,2) nowy.t[a][b] = 0;
        REP(a,2)REP(b,2)REP(c,2)
            nowy.t[a][c] = (nowy.t[a][c] + (ll) t[a][b] * other.t[b][c]) % mod;
        //REP(a,2)REP(b,2) printf("%d ", nowy.t[a][b]); puts("");
        return nowy;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    T ans;
    ans.t[0][0] = 0;
    ans.t[0][1] = 2;
    ans.t[1][0] = 1;
    ans.t[1][1] = 1;
    int two = 2;
    while(n--) {
        ll x;
        scanf("%lld", &x);
        T m;
        m.t[0][0] = m.t[1][1] = 1;
        m.t[0][1] = m.t[1][0] = 0;
        int m2 = 1;
        while(x) {
            if(x % 2) {
                    m = m * ans;
                    m2 = (ll) m2 * two % mod;
            }
            ans = ans * ans;
            two = (ll) two * two % mod;
            x /= 2;
        }
        ans = m;
        two = m2;
    }
    const ll inv = 500000004;
    printf("%lld/%lld\n", ans.t[0][0] * inv % mod, two * inv % mod);
    return 0;
}