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
 
// const ll mod = 998244353ll;
const ll mod = 1000000007ll;
  
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
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/

bool multicase = false;

ll n,m,num,a,b,c,d,e,h,q;
ll w, k, l, r;
ll x[500005], y[500005], z[500005];
vector<ll> G[500005];

void dfs1(ll v, ll dis, ll p){
    x[v] = dis;
    for(ll i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        if(nv == p)continue;
        dfs1(nv, dis + 1, v);
    }
    return;
}


void dfs2(ll v, ll p){
    ll res = 1;
    for(ll i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        if(nv == p)continue;
        dfs2(nv, v);
        res += y[nv];
    }
    y[v] = res;
    return;
}

void solve(){
    cin >> n >> k;
    for(ll i=0;i<n-1;i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs1(1, 0, -1);
    dfs2(1, -1);
    for(ll i=1;i<=n;i++){
        y[i]--;
        z[i] = x[i] - y[i];
    }
    sort(z + 1, z + n + 1);
    ll ans = 0;
    for(ll i=n;i>n-k;i--){
        ans += z[i];
    }
    p(ans);
    return;
}


int main(){
    // init();
    // 
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