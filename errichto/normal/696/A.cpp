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

map<ll, ll> m;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int type;
        ll a, b, c;
        scanf("%d%lld%lld", &type, &a, &b);
        if(type == 1) scanf("%lld", &c);
        ll ans = 0;
        while(a != b) {
            if(a < b) swap(a, b);
            if(type == 1) m[a] += c;
            else ans += m[a];
            a /= 2;
        }
        if(type == 2) printf("%lld\n", ans);
    }
    return 0;
}