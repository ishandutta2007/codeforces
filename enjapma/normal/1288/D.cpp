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
ll x[500005], y[500005], z[200005];
char s[500005], t[500005];
bool used[500005];
ll dp[5000005][10];
 
bool solve(ll mid){
    // Maxmid
    for(ll i=0;i<(1ll << m);i++){
        x[i] = 0;
    }
    vector<ll> mybit_table;
    for(ll i=0;i<n;i++){
        ll mybit = 0;
        for(ll j=0;j<m;j++){
            if(dp[i][j] >= mid){
                mybit += (1ll << j);
            }
        }
        mybit_table.pb(mybit);
        x[mybit]++;
    }
    for(ll i=0;i<m;i++){
        for(ll bit=0;bit<(1ll << m);bit++){
            if(!((bit >> i) & 1ll))x[bit] += x[bit ^ (1ll << i)];
        }
    }
    bool ok = false;
    for(ll i=0;i<n;i++){
        ll mybit = mybit_table[i];
        ll otherbit = (1ll << m) - 1 - mybit;
        if(x[otherbit] >= 1){
            ok = true;
            break;
        }   
    }
    return ok;
}
 
P solve_rev(ll mid){
    for(ll i=0;i<(1ll << m);i++){
        x[i] = 0;
    }
    vector<ll> mybit_table;
    for(ll i=0;i<n;i++){
        ll mybit = 0;
        for(ll j=0;j<m;j++){
            if(dp[i][j] >= mid){
                mybit += (1ll << j);
            }
        }
        mybit_table.pb(mybit);
        x[mybit]++;
    }
    for(ll i=0;i<m;i++){
        for(ll bit=0;bit<(1ll << m);bit++){
            if(!((bit >> i) & 1ll))x[bit] += x[bit ^ (1ll << i)];
        }
    }
    bool ok = false;
    ll ans1 = -1, ans2 = -1;
    for(ll i=0;i<n;i++){
        ll mybit = mybit_table[i];
        ll otherbit = (1ll << m) - 1 - mybit;
        if(x[otherbit] >= 1){
            for(ll j=0;j<n;j++){
                bool ok = true;
                for(ll k=0;k<m;k++){
                    if(max(dp[i][k], dp[j][k]) < mid)ok = false;
                }
                if(ok){
                    ans1 = i;
                    ans2 = j;
                    return P(ans1, ans2);
                }
            }
        }   
    }
    assert(0);
    return P(1, 1);
}
int main(){
    /*
    cin.tie(0);
    ios::sync_with_stdio(false);
    */
    cin >> n >> m;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> dp[i][j];
        }
    }
    ll ok = 0, ng = INF;
    
    while(ng - ok > 1){
        // pe(ok);p(ng);
        ll mid = (ok + ng) / 2;
        bool res = solve(mid);
        if(res){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //ok = solve(100);
    P ans = solve_rev(ok);
    pe(ans.first + 1);p(ans.second + 1);
    //p(ok);
    return 0;
}