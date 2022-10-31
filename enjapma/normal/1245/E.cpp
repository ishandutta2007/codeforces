#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800000;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
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

 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k,idx,ans;
ll x[500005],y[500005],z[500005];
char s[500005];
long double dp[500005];

ll place(ll i,ll j){
    if(i % 2 == 0){
        return (99 - i * 10) - j;
    }else{
        return (90 - i * 10) + j;
    }
}

long double calc(ll idx){
    if(G[idx].size() == 0){
        return dp[idx];
    }else{
        long double sum = dp[idx];
        for(int i=0;i<G[idx].size();i++){
            ll nv = G[idx][i];
            sum = min(sum, dp[nv]);
        }
        return sum;
    }
}
int main(){
    n = 10;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            if(a == 0){
                continue;
            }else{
                ll from = place(i, j);
                ll to = place(i - a, j);
                G[from].pb(to);
            }
        }
    }
    for(int i=0;i<99;i++){
       // G[i].pb(i + 1);
    }
    dp[99] = 0.0f;
    for(int i=98;i>=0;i--){
        long double sum = 0.0f;
        ll dame = 0;
        for(int dice = 1;dice <= 6;dice++){
            if(dice + i >= 100){
                dame += 1;
            }else{
                sum += (calc(dice + i) + 1.0f);
            }
        }
        dp[i] = ((sum + dame) / (6.0f - dame));
        //pe(i);ps(dp[i]);
    }
    ps(dp[0]);



    return 0;
    
}