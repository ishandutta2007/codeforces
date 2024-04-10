#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
//vector<P> tree[500010];
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
 
ll n,m,num,sum,a,b,c,d,e,h,r,l;
ll k;
ll ans;
ll x[500005], y[500005];
bool used[4][500005];
char s[500005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ax, ay, bx, by;
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> k;
    ll minidx = -1;
    ll minidist = INF;
    for(ll i=0;i<100;i++){
        if(x[i] == INF){
            x[i+1] = INF;
        }else{
            x[i+1] = ax * x[i] + bx;
            if(x[i+1] >= 2e16)x[i+1] = INF;
        }
        if(y[i] == INF){
            y[i+1] = INF;
        }else{
            y[i+1] = ay * y[i] + by;
            if(y[i+1] >= 2e16)y[i+1] = INF;
        }
    }
    ll finalans = 0;
    for(ll i=0;i<100;i++){
        ll ans = 0;
        ll minidx = i;
        ll minidist = abs(x[minidx] - xs) + abs(y[minidx] - ys);
        ll t = k;
        t -= minidist;
        if(t < 0){
            continue;
        }
        ans ++;
        ll ok = minidx, ng = 99;
        while(ng - ok > 1){
            ll mid = (ok + ng) / 2;
            if(abs(x[mid] - x[minidx]) + abs(y[mid] - y[minidx]) <= t){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll ans1 = max(ans, ok - minidx + ans);
        ok = minidx, ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(abs(x[mid] - x[minidx]) + abs(y[mid] - y[minidx]) <= t){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll ans2 = max(ans, minidx - ok + ans);
        ans = max(ans1, ans2);
        finalans = max(finalans, ans);
    }
    p(finalans);
    return 0;
}