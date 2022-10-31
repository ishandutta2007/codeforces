#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
vector<P> tree[500010];
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
 
ll n,m,num,sum,a,b,c,d,e,h,r,l,q;
ll k;
ll ans;
ll x[500005], y[500005], z[500005];
char s[500005];
ll dp[1000005];

ll dfs(ll idx, vector<ll>& v){
    ll cnt = 0;
    if(v.size() <= 1){
        return 0;
    }
    if(idx <= -1){
        return 0;
    }
    vector<ll> v1, v0;
    for(ll i=0;i<v.size();i++){
        if(v[i] & (1ll << idx)){
            // bit
            v1.pb(v[i]);
        }else{
            v0.pb(v[i]);
        }
    }
    if(v0.empty()){
        ll ans1 = dfs(idx - 1, v1);
        return ans1;
    }else if(v1.empty()){
        ll ans0 = dfs(idx - 1, v0);
        return ans0;
    }else{
        ll ans1 = dfs(idx - 1, v1);
        ll ans0 = dfs(idx - 1, v0);
        return min(ans0, ans1) + (1ll << idx);
    }
}
int main(){
    cin >> n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        cin >> x[i];
        v.pb(x[i]);
    }
    ll ans = dfs(33, v);
    p(ans);
    return 0;
}