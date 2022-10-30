#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;
 
//vector<ll> G[550010];
vector<P> tree[500010];
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
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 
 
//ll mod = 998244353;
ll mod = 1000000007;
 
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
 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;
ll ans;
ll x[500005], y[500005], z[200005];
char s[500005], t[500005];
bool used[500005];
ll pri[500005];
ll maxidx[500005];

struct SegmentTree {
private:
    int n;
    vector<ll> node;
public:
    SegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
 
    void update(int k, ll val) {
        // update node[k] to val (0-indexed)
        k += (n - 1);
        node[k] = val;
        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        //sum of [a, b)
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(){
    /*
    cin.tie(0);
    ios::sync_with_stdio(false);
    */
    cin >> n >> m;
    set<ll> st;

    SegmentTree seg( vector<ll>(n + m + 20, 0ll) );
    for(ll i=0;i<n;i++){
        seg.update(n + 1 - i, 1);
        pri[i+1] = n + 1 - i;
        maxidx[i+1] = i + 1;
    }
    for(ll i=0;i<m;i++){
        cin >> x[i];
        used[x[i]] = true;
    }
    ll next_pri = n + 10;
    for(ll i=0;i<m;i++){
        ll next = x[i];
        ll now_pri = pri[next];
        
        ll rank = seg.getsum(1, now_pri);
        rank = n - rank;
        // setnow_pri

        maxidx[next] = max(maxidx[next], rank);

        // setnow_pri
        seg.update(now_pri, 0);
        // setnext_pri
        pri[next] = next_pri;
        seg.update(next_pri, 1);
        next_pri ++;
    }
    for(ll i=1;i<=n;i++){
        ll now_pri = pri[i];
        ll rank = seg.getsum(1, now_pri);
        rank = n - rank;
        maxidx[i] = max(maxidx[i], rank);
    }
    for(ll i=1;i<=n;i++){
        if(used[i]){
            pe(1);
        }else{
            pe(i);
        }
        p(maxidx[i]);
    }
    return 0;
}