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
ll x[500005], y[500005];
ll use[1000];

void init(){
    struct timeval _time;
    gettimeofday(&_time, NULL);
    ll usec = _time.tv_usec * 1000000;
    srand(usec);
    return;
}

ll dp[100][100];
vector<P> table[100][100];
vector<ll> pass;

void solve(){
    cin >> n >> k;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> dp[i][j];
            if(i == j)dp[i][j] = INF;
        }
    }
    for(ll k=1;k<n;k++){
        for(ll i=0;i<n;i++){
            if(i == k)continue;
            for(ll j=0;j<n;j++){
                if(j == k)continue;
                table[i][j].pb(P(dp[i][k] + dp[k][j], k));
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            sort(table[i][j].begin(), table[i][j].end());
        }
    }
    ll times = k / 2 - 1;
    ll idx = 1;
    for(ll i=0;i<times;i++){
        idx *= n;
    }
    ll ans = INF;
    for(ll i=0;i<times+2;i++){
        pass.pb(0);
    }
    use[0] = n;
    for(ll i=0;i<idx;i++){
        ll tmp = 0;
        ll num = i;
        for(ll j=times;j>=0;j--){
            if(i == 0)break;
            use[pass[j]]--;
            pass[j]++;
            use[pass[j]]++;
            if(pass[j] >= n){
                use[pass[j]]--;
                pass[j] = 0;
                use[pass[j]]++;
            }else{
                break;
            }
        }
        for(ll j=0;j<pass.size()-1;j++){
            ll v1 = pass[j], v2 = pass[j+1];
            ll dis = INF;
            for(ll j1=0;j1<table[v1][v2].size();j1++){
                if(!use[table[v1][v2][j1].second]){
                    dis = table[v1][v2][j1].first;
                    break;
                }
            }
            tmp += dis;
            if(tmp > ans)break;
        }
        ans = min(ans, tmp);
        // if(i % 1000000 == 0)p(i);
    }
    p(ans);



    return;
}

int main(){
    // init();
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