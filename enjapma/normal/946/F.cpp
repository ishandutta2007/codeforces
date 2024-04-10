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
ll x[100005], y[500005], z[200005];
char s[500005];
ll dp[104][104][104];
ll query;
ll len[105];
 
int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    cin >> s;
    m = n;
    n = k;
    for(ll i=0;i<m;i++){
        if(s[i] == '1'){
            dp[1][i][i] = 1;
        } else {
            dp[0][i][i] = 1;
        }
    }
    len[0] = 2;
    len[1] = 2;
    for(ll i=2;i<=n;i++){
        len[i] = len[i-1] * len[i-2];
        len[i] %= mod;
    }
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<m;j++){
            for(ll k=j;k<m;k++){
                // dp[i][j][k] 
                if(j == 0 && k == m - 1){
                    dp[i][j][k] += dp[i-1][j][k] * len[i-2] + dp[i-2][j][k] * len[i-1];
                }else if(j == 0){
                    dp[i][j][k] += dp[i-1][j][k] + dp[i-2][j][k] * len[i-1];
                }else if(k == m - 1){
                    dp[i][j][k] += dp[i-2][j][k] + dp[i-1][j][k] * len[i-2];
                }else{
                    dp[i][j][k] += dp[i-1][j][k] + dp[i-2][j][k];
                }
                dp[i][j][k] %= mod;
                for(ll l=j;l<k;l++){
                    dp[i][j][k] += dp[i-1][j][l] * dp[i-2][l+1][k];
                    dp[i][j][k] %= mod;
                }
                dp[i][j][k] %= mod;
            }
        }
    }
    ans = dp[n][0][m-1];
    p(ans);

    return 0;
}