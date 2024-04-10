#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 2e18;
const ll fact_table = 1200008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//,,,

#define endl "\n"
#ifdef ENJAPMA
    #undef endl
#endif
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
const ll mod = 998244353ll;
// const ll mod = 1000000007ll;
  
ll mypow(ll number1,ll number2, ll mod){
    if(number2 == 0){
        return 1ll;
    }else{
        ll number3 = mypow(number1,number2 / 2, mod);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
void YES(bool condition){
    if(condition){ p("YES"); }else{ p("NO"); }
    return;
}
void Yes(bool condition){
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}

ll mygcd(ll a, ll b){
    if(b > a)swap(a, b);
    if(a == b || b == 0)return a;
    return mygcd(b, a % b);
}

ll fact[fact_table + 5],rfact[fact_table + 5]; 
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    assert(n >= r);
    assert(n >= 0);
    assert(r >= 0);
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}


struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
 
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        assert(a < b);
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

// auto res = NTT::conv(mod, 3ll, atable, btable);

bool multicase = false;

ll n,m,num,a,b,c,d,e,q, w;
ll x[500005], y[500005];
ll sum, r, k;
vector<ll> dp, base;

void solve(){
    c3_init();
    cin >> n;
    ll after = 0, before = 0;
    for(ll i=0;i<n;i++){
        cin >> x[i];
        if(x[i] == -1){
            after ++;
        }else{
            y[x[i]]--;
        }
    }
    for(ll i=1;i<=n;i++){
        y[i] ++;
    }
    for(ll i=2;i<=n;i++){
        y[i] += y[i-1];
    }
    ll m = after;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(x[i] != -1){
            ll small = y[x[i]];
            ll large = m - small;
            ll res = (before * large) % mod + (after * small) % mod;
            res %= mod;
            res *= fact[m - 1];
            res %= mod;
            ans += res;
            ans %= mod;
        }else{
            after --;
            before ++;
        }
    }
    ll tmp = 0;
    LazySegmentTree seg(vector<ll> (n + 10, 0));
    for(ll i=0;i<n;i++){
        if(x[i] != -1){
            tmp += seg.getsum(x[i] + 1, n + 1);
            tmp %= mod;
            seg.add(x[i], x[i] + 1, 1ll);
        }
    }
    if(m == 0){
        p(tmp);
        return;
    }
    tmp *= fact[m];
    tmp %= mod;
    ans += tmp;
    ans %= mod;
    tmp = 0;
    tmp = m * (m - 1) / 2;
    tmp %= mod;
    tmp *= mypow(2ll, mod - 2, mod);
    tmp %= mod;
    tmp *= fact[m];
    tmp %= mod;
    ans += tmp;
    ans %= mod;
    ans *= rfact[m];
    ans %= mod;
    p(ans);
    return;
}

int main(){
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, testcase = 1;
    if(multicase){
        cin >> q;
    }else{
        q = 1; 
    }
    while(q--){
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    // solve();
    return 0;
}