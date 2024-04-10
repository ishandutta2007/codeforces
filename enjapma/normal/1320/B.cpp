#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
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
bool multicase = false;

ll n,m,num,sum,a,b,c,d,e,h,q;
ll w, ans;
ll k;
char s[500005], t[500005];
ll x[500005], y[500005], z[1000005];
ll cost[500005];
vector<ll> G[500005];
vector<ll> H[500005];
void init(){
    struct timeval _time;
    gettimeofday(&_time, NULL);
    ll usec = _time.tv_usec * 1000000;
    srand(usec);
    return;
}

void solve(){
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a >> b;
        G[b].pb(a);
        H[a].pb(b);
    }
    cin >> k;
    for(ll i=0;i<k;i++){
        cin >> x[i];
    }
    ll s, t;
    s = x[0], t = x[k - 1];

    queue<ll> que;
    for(ll i=1;i<=n;i++){
        cost[i] = INF;
    }
    que.push(t);
    cost[t] = 0;
    while(que.size()){
        ll v = que.front(); que.pop();
        for(ll i=0;i<G[v].size();i++){
            ll nv = G[v][i];
            if(cost[nv] == INF){
                que.push(nv);
                cost[nv] = cost[v] + 1;
            }
        }
    }
    ll ansmin = 0, ansmax = 0;
    for(ll i=0;i<k-1;i++){
        if(cost[x[i+1]] >= cost[x[i]])ansmin++;
    }
    for(ll i=0;i<k-1;i++){
        ll v = x[i];
        bool find = false;
        for(ll j=0;j<H[v].size();j++){

            ll nv = H[v][j];
            if(nv != x[i+1] && cost[nv] + 1 == cost[v]){
                find = true;
            }
        }
        if(find)ansmax++;
    }
    pe(ansmin);p(ansmax);



    return;
}

int main(){
    // init();
    ll q;
    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        solve();
    }
    return 0;

}