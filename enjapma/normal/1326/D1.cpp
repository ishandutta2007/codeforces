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

void fast(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return;
}
 
ll n,m,num,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;
bool dp[5005][5005];
string s;

void solve(){
    cin >> s;
    n = s.size();
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            dp[i][j] = false;
        }
    }
    for(ll len=0;len<=n;len++){
        for(ll i=0;i+len<n;i++){
            ll j = i + len;
            if(len == 0){
                dp[i][j] = true;
            }else if(len == 1){
                if(s[i] == s[j])dp[i][j] = true;
            }else{
                if(s[i] == s[j] && dp[i+1][j-1])dp[i][j] = true;
            }
        }
    }
    ll ans = 1;
    P t = P(1, 0);
    for(ll i=0;i<n;i++){
        if(dp[0][i]){
            if(ans < i + 1){
                ans = i + 1;
                t = P(i + 1, 0);
            }
        }
        if(dp[n-i-1][n-1]){
            if(ans < i + 1){
                ans = i + 1;
                t = P(0, i + 1);
            }
        }
    }
    for(ll i=0;i<n;i++){
        if(i >= n - i - 1)break;
        if(s[i] != s[n-i-1])break;
        for(ll j=i+1;j<n-i-1;j++){
            if(dp[i+1][j]){
                if(ans < i + j + 2){
                    ans = i + j + 2;
                    t = P(j + 1, i + 1);
                }
            }
            if(dp[j][n-i-2]){
                if(ans < i + n - j + 1){
                    ans = i - j + n + 1;
                    t = P(i + 1, n - j);
                }
            }
        }
    }
    pu(s.substr(0, t.first));
    p(s.substr(n - t.second, t.second));
    return;
}

int main(){
    // fast();
    ll q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}