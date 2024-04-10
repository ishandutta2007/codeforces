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
ll x[100005], y[505], z[200005];
ll timedp[505][505];
ll rec[505];
ll dp[505];
ll dpnew[505];
char s[505];
bool used[2000005];

void solve(){

}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
    for(ll q=0;q<n;q++){
        cin >> s;
        ll last = -1;
        ll idx = 0;
        ll sum = 0;
        for(ll i=0;i<m;i++){
            if(s[i] == '0')continue;
            y[idx++] = i;
        }
        if(idx == 0){
            // 
            rec[q] = 0;
            timedp[q][0] = 0;
        }else if(idx == 1){
            // 
            rec[q] = 1;
            timedp[q][0] = 1;
            timedp[q][1] = 0;
        }else{
            // 
            rec[q] = idx;
            for(ll j=0;j<=idx;j++){
                // timedp[j]
                ll attend = idx - j;
                ll maxi = INF;
                if(j == 0){
                    timedp[q][j] = y[idx - 1] - y[0] + 1;
                }else if(j == idx){
                    timedp[q][j] = 0;
                }else{
                    for(ll k=0;k+attend - 1<idx;k++){
                        maxi = min(maxi, y[k + attend - 1] - y[k] + 1);
                    }
                    timedp[q][j] = maxi;
                }
            }
        }
    }
    for(ll i=1;i<=500;i++){
        dp[i] = INF;
        dpnew[i] = INF;
    }
    dpnew[0] = INF;
    for(ll i=0;i<n;i++){
    }
    ll limit = k;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=500;j++){
            for(ll k=0;k<=rec[i];k++){
                if(j + k > limit)continue;
                dpnew[j + k] = min(dpnew[j + k], dp[j] + timedp[i][k]);
            }
        }
        for(ll j=0;j<=500;j++){
            dp[j] = dpnew[j];
            dpnew[j] = INF;
        }
    }
    ans = dp[limit];
    if(ans == INF){
        p(0);
        return 0;
    }
    p(dp[limit]);


	return 0;
}