#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;
 
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
#define ps(x) cout<<fixed<<setprecision(8)<<x<<"\n";
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
ll mod1 = 2000000011;
ll mod2 = 2000000033;


ll rui1(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui1(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod1;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod1;
        }
        return number3;
    }
}

ll rui2(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui2(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod2;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod2;
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
 
ll n,m,num,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;
ll ans;
ll x[500005], y[500005], z[200005];
char s[500005];
vector<P> G[550010];

ll cost[500005];


void solve(){
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a >> b >> c;
        c *= 2;
        G[a].pb(P(b, c));
        G[b].pb(P(a, c));
    }
    for(ll i=1;i<=n;i++){
        cin >> x[i];
    }
    for(ll i=1;i<=n;i++){
        G[i].pb(P(i+n, x[i]));
        G[i+n].pb(P(i, x[i]));
        G[i+n].pb(P(2*n+1, 0));
        G[2*n+1].pb(P(i+n, 0));
    }
    ll k = 2 * n + 1;
    for(ll i=1;i<=k-1;i++){
        cost[i] = INF;
    }
    pqps.push(P(0, k));
    cost[k] = 0;
    while(!pqps.empty()){
        P p = pqps.top();
        pqps.pop();
        ll v = p.second;
        ll nowcost = p.first;
        if(nowcost > cost[v])continue;
        for(ll i=0;i<G[v].size();i++){
            ll nv = G[v][i].first;
            ll newcost = cost[v] + G[v][i].second;
            if(cost[nv] > newcost){
                cost[nv] = newcost;
                pqps.push(P(newcost, nv));
            }
        }
    }
    for(ll i=1;i<=n;i++){
        pe(cost[i]);
    }
    el;
    return;


}
int main(){
    q = 1;
    while(q--){
        solve();
    }
    return 0;
}