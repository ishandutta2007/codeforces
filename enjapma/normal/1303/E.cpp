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
 
 
ll mod = 998244353;
//ll mod = 1000000007;
 
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
ll x[500005], y[500005], z[500005];
char s[500005], t[500005];
ll dp[505][505];

bool solve_dp(ll l1, ll r1, ll l2, ll r2){
    for(ll i=0;i<500;i++){
        for(ll j=0;j<500;j++){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=r1+1;j++){
            if(i == 0 && j == 0)continue;
            if(i>=1 && j>=1){
                if(s[i-1] == t[j-1])dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            if(i>=1 && dp[i-1][j] >= 0){
                if(s[i-1] == t[l2 + dp[i-1][j]])dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
            }
            if(i>=1)dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    if(dp[n][r1 - l1 + 1] >= r2 - l2 + 1){
        return true;
    }else{
        return false;
    }
}
void solve(){
    cin >> s >> t;
    n = strlen(s);
    m = strlen(t);
    if(m == 1){
        for(ll i=0;i<n;i++){
            if(s[i] == t[0]){
                p("YES");
                return;
            }
        }
        p("NO");
        return;
    }
    for(ll i=0;i<m-1;i++){
        bool res = solve_dp(0, i, i+1, m-1);
        if(res){
            p("YES");
            return;
        }
    }
    p("NO");
    return;

    
    
}
int main(){
    cin >> q;
    while(q--){
        solve();
    }

    return 0;
}