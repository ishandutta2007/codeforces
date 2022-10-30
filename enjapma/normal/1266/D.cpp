#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 1e18;
const ll fact_table = 5000000;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
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
 
ll n,m,num,sum,a,b,c,d,e,f,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
bool used[500005];
char s[500005];
ll one[500005], two[500005], three[500005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a >> b >> c;
        x[a] -= c;
        x[b] += c;
    }
    vector<ll> plus, minus;
    for(ll i=1;i<=n;i++){
        if(x[i] > 0){
            plus.pb(i);
        }else if(x[i] < 0){
            minus.pb(i);
        }
    }
    ll idx = 0;
    while(true){
        if(plus.size() == 0 || minus.size() == 0)break;
        ll from = plus.back();
        ll to = minus.back();
        plus.pop_back();
        minus.pop_back();
        ll flow = min(abs(x[from]), abs(x[to]));
        one[idx] = to;
        two[idx] = from;
        three[idx] = flow;
        idx ++;
        x[from] -= flow;
        x[to] += flow;
        if(x[from] != 0){
            plus.pb(from);
        }
        if(x[to] != 0){
            minus.pb(to);
        }
        if(plus.size() == 0 || minus.size() == 0)break;
    }
    p(idx);
    for(ll i=0;i<idx;i++){
        pe(one[i]);pe(two[i]);p(three[i]);
    }
    return 0;
}