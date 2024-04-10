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
char s[500005];
bool used[50][50];
bool visited[50];
vector<ll> G[505];

void solve(){
    cin >> n >> m;
    for(ll i=0;i<60;i++){
        y[i] = 0;
    }
    for(ll i=0;i<m;i++){
        cin >> x[i];
        for(ll j=0;j<60;j++){
            if((1ll << j) == x[i]){
                y[j]++;
            }
        }
    }
    ll idx = 1;
    ll cnt = n;
    ll reside = 0;
    ll ans = 0;
    vector<P> cons;
    cons.clear();
    while(true){
        if(cnt % (1ll << idx) != 0){
            cons.pb(P(idx, reside + cnt % (1ll << idx)));
            reside += cnt % (1ll << idx);
            cnt -= cnt % (1ll << idx);
        }
        idx ++;
        if(cnt == 0)break;
    }
    ll l, r = -1;
    for(ll i=0;i<cons.size();i++){
        l = r + 1;
        r = cons[i].first - 1;
        ll tmp = r - l;
        ll aim = cons[i].second;
        ll cnt = 0;
        for(ll j=0;j<=r;j++){
            cnt += (1ll << j) * y[j];
            if(cnt >= aim)break;
        }
        if(cnt >= aim)continue;
        ll near = -1;
        for(ll j=r+1;j<=60;j++){
            if(y[j] >= 1){
                near = j;
                break;
            }
        }
        if(near == -1){
            p(-1);
            return;
        }
        for(ll j=near;j>r;j--){
            y[j] -= 1;
            y[j-1] += 2;
            ans ++;
        }
    }
    p(ans);

    return;
}
int main(){
    cin >> q;
    while(q--){
        solve();
    }

    return 0;
}