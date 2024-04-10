#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 1e18;
const ll fact_table = 1000000;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
vector<ll> R[550010];
vector<pair<ll, double> > tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//,,,
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<"\n";
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 
 
//ll mod = 998244353;
ll mod;
 
ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
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
 
/*
ll fact[fact_table + 5],rfact[fact_table + 5];
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    
    rfact[fact_table] = rui(fact[fact_table],mod - 2);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/
 
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, INF);
        lazyFlag.resize(2*n-1, false);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
 
    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = min(lazy[k], node[k]);
            if(r - l > 1) {
                lazy[k*2+1] = min(lazy[k*2+1], lazy[k]);
                lazy[k*2+2] = min(lazy[k*2+2], lazy[k]);
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }
 
    void update(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        //update node[a, b) to x
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }
 
    ll find(int a, int b, int k=0, int l=0, int r=-1) {
        //find minimum of node[a, b)
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2*k+1, l, (l+r)/2);
        ll vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

ll n,m,num,sum,a,b,c,d,e,f,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
ll mini[500005], maxi[500005];
ll dp[5005][5005];
bool used[500005];
ll limit[500005];
vector<ll> v;
tuple<ll, ll, ll, ll> table[100005];

bool solve1(){
    sort(v.begin(), v.end());
    sort(table, table + n);
    for(ll i=0;i<n;i++){
        if(get<0>(table[n-1]) <= get<1>(table[i])){
            // 
            limit[i] = n - 1;
        }else{
            ll ok = i, ng = n - 1;
            while(ng - ok > 1){
                ll mid = (ok + ng) / 2;
                if(get<0>(table[mid]) <= get<1>(table[i])){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            limit[i] = ok;
        }
    }
    for(ll i=0;i<n;i++){
        x[i] = lb(v.begin(), v.end(), get<2>(table[i])) - v.begin();
        y[i] = lb(v.begin(), v.end(), get<3>(table[i])) - v.begin();
    }
    bool find = false;
    LazySegmentTree seg_l( vector<ll>(3 * n, INF) );
    LazySegmentTree seg_r( vector<ll>(3 * n, INF) );
    for(ll i=n-1;i>=0;i--){
        ll l = x[i];
        ll r = y[i];
        if(i != n - 1){
            // 2_i ~ 3_i limit[i]
            ll leftfind = seg_r.find(0, l);
            ll rightfind = seg_l.find(r + 1, 3 * n);
            //pe(leftfind);
            //p(rightfind);
            if(leftfind <= limit[i] || rightfind <= limit[i]){
                find = true;
                return true;
            }
        }
        // 2_i ~ 3_i i
        seg_l.update(l, l + 1, i);
        seg_r.update(r, r + 1, i);
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        get<0>(table[i]) = a;
        get<1>(table[i]) = b;
        get<2>(table[i]) = c;
        get<3>(table[i]) = d;
        v.pb(c);
        v.pb(d);
    }
    bool find1 = solve1();
    v.clear();
    for(ll i=0;i<n;i++){
        v.pb(get<1>(table[i]));
        v.pb(get<2>(table[i]));
        swap(get<0>(table[i]), get<2>(table[i]));
        swap(get<1>(table[i]), get<3>(table[i]));
    }
    bool find2 = solve1();
    if(find1 || find2){
        p("NO");
    }else{
        p("YES");
    }


    return 0;
}