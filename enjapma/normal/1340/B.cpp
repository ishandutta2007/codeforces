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
ll w, k;
ll x[500005], y[500005];
string digit[15] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", 
                "1010010", "1111111", "1111011"};
string s[5005];

bool dp[2005][14005];

ll can(ll idx, ll num){
    // s[idx]num
    // INF
    ll cnt = 0;
    for(ll j=0;j<7;j++){
        if(digit[num][j] == '1' && s[idx][j] == '0')cnt ++;
        if(digit[num][j] == '0' && s[idx][j] == '1'){
            cnt = INF;
            break;
        }
    }
    return cnt;
}

void solve(){
    cin >> n >> k;
    for(ll i=0;i<n;i++){
        cin >> s[i];
    }
    dp[0][0] = true;

    vector<ll> cnts;
    for(ll i=1;i<=n;i++){
        cnts.clear();
        for(ll k=0;k<10;k++){
            cnts.pb(can(n - i, k));
        }
        for(ll j=0;j<=7*i;j++){
            // dp[i][j]
            for(ll k=0;k<10;k++){
                ll cnt = cnts[k];
                if(j - cnt < 0)continue;
                dp[i][j] = dp[i][j] || dp[i-1][j-cnt];
                if(dp[i][j])break;
            }
        }
    }
    if(!dp[n][k]){
        p(-1);
    }else{
        ll sum = k;
        for(ll i=n;i>=1;i--){

            for(int num=9;num>=0;num--){
                ll cnt = can(n - i, num);
                if(sum - cnt < 0)continue;
                if(dp[i-1][sum-cnt]){
                    pu(num);
                    sum -= cnt;
                    break;
                }
            }
        }
        el;
    }
    return;
}

int main(){
    // init();
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