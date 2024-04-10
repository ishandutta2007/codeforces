#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 1000008;
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
#define el cout<<"\n";
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

struct edge {ll to,cost,idx; } ;

vector<edge> G[200005];
void fast(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return;
}
 
ll n,m,num,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;

ll x[500005];
ll y[500005];
ll z[500005];
bool used[500005];

void solve(){
    cin >> n >> m;
    vector<P> edges;
    ll sum = 0;
    for(ll i=0;i<m;i++){
        cin >> a >> b >> c;
        G[a].pb((edge){b, c, i});
        G[b].pb((edge){a, c, i});
        y[a] += c;
        y[b] += c;
        edges.pb(P(a, b));
        if(a == 1 || b == 1){
            sum += c;
        }
    }
    x[1] = sum;
    x[n] = -sum;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        used[v] = true;
        for(ll i=0;i<G[v].size();i++){
            ll cost = G[v][i].cost;
            ll nv = G[v][i].to;
            if(used[nv])continue;
            x[v] -= cost;
            x[nv] += cost;
            ll id = G[v][i].idx;
            if(edges[id].first == v)z[id] = 1;
            if(x[nv] * 2 == y[nv]){
                q.push(nv);
            }
        }
    }
    for(ll i=0;i<m;i++){
        p(1-z[i]);
    }

    return;
}

int main(){
    // fast();
    q = 1;
    while(q--){
        solve();
    }
    return 0;
}