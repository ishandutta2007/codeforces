#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
// priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//,,,
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
// #define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
 
// ll mod = 998244353;
 ll mod = 1000000007;
  
ll mypow(ll number1,ll number2, ll mod){
 
    if(number2 == 0){
        return 1;
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

ll n,m,num,sum,a,b,d,e,h,r,l,q;
ll k;
ll x[500005], y[500005], z[500005];
ll from1[500005], fromn[500005];
vector<ll> G[200005];
char s[500005], t[500005];

void bfs_from1(){
    for(ll i=1;i<=n;i++){
        from1[i] = INF;
    }
    queue<ll> q;
    q.push(1);
    from1[1] = 0;
    while(q.size()){
        ll v = q.front();q.pop();
        if(v == n)break;
        for(ll i=0;i<G[v].size();i++){
            ll nv = G[v][i];
            if(from1[nv] != INF)continue;
            q.push(nv);
            from1[nv] = from1[v] + 1;
        }
    }
}


void bfs_fromn(){
    for(ll i=1;i<=n;i++){
        fromn[i] = INF;
    }
    queue<ll> q;
    q.push(n);
    fromn[n] = 0;
    while(q.size()){
        ll v = q.front();q.pop();
        if(v == 1)break;
        for(ll i=0;i<G[v].size();i++){
            ll nv = G[v][i];
            if(fromn[nv] != INF)continue;
            q.push(nv);
            fromn[nv] = fromn[v] + 1;
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    vector<ll> special;
    vector<P> res1, resn;
    for(ll i=0;i<k;i++){
        cin >> a;
        special.pb(a);
    }
    for(ll i=0;i<m;i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    bfs_from1();
    bfs_fromn();
    ll ans = from1[n];
    for(ll i=0;i<special.size();i++){
        ll v = special[i];
        res1.pb(P(from1[v], i));
        resn.pb(P(fromn[v], i));
    }
    sort(res1.begin(), res1.end());
    ll tmp = 0;
    for(ll i=0;i<res1.size() - 1;i++){
        ll idx1 = special[res1[i].second];
        ll idx2 = special[res1[i+1].second];
        tmp = max(tmp, min(from1[idx1] + fromn[idx2], fromn[idx1] + from1[idx2]) + 1);
    }

    sort(resn.begin(), resn.end());

    for(ll i=0;i<res1.size() - 1;i++){
        ll idx1 = special[resn[i].second];
        ll idx2 = special[resn[i+1].second];
        tmp = max(tmp, min(from1[idx1] + fromn[idx2], fromn[idx1] + from1[idx2]) + 1);
    }
    ans = min(ans, tmp);

    p(ans);

}
int main(){
    solve();
    
    return 0;
}