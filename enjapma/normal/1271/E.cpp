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
ll reside[500005], memo[500005];
bool used[500005], got[400004];
char s[500005];

ll count(ll num){
    //pe("count ");pe(num);
    ll cnt = 0;
    if(num == 1){
        return n;
    }
    if(num == 2){
        return n - 1;
    }
    if(num % 2 == 1){
        cnt ++;
        num = 2 * num;
    }
    ll low = num, high = num + 1;
    while(true){
        if(low > n)break;
        cnt += min(high, n) - low + 1;
        low *= 2;
        high = high * 2 + 1;
    }
    //pe(" ");p(cnt);
    return cnt;
}

ll solve_even(){
    ll ok = 0, ng = INF / 2;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        ll cnt = count(mid * 2);
        if(cnt >= k){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok * 2;
}

ll solve_odd(){
    ll ok = 0, ng = INF / 2;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        ll cnt = count(mid * 2 + 1);
        if(cnt >= k){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok * 2 + 1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k == 1){
        p(n);
        return 0;
    }
    ll even, odd;
    even = solve_even();
    odd = solve_odd();
    ans = max(even, odd);
    p(ans);

    return 0;
}