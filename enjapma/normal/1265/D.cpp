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
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
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
 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
char s[500005];
ll v1, v2, v3, v4;
 
bool solve(ll i1,ll i2){
    ll k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    if(i1 == 0)k1++;
    if(i1 == 1)k2++;
    if(i1 == 2)k3++;
    if(i1 == 3)k4++;
    if(i2 == 0)k1++;
    if(i2 == 1)k2++;
    if(i2 == 2)k3++;
    if(i2 == 3)k4++;
    ll e1, e2, e3;
    e1 = 2 * v1 - k1;
    e3 = 2 * v4 - k4;
    e2 = n - 1 - e1 - e3;
    //pe(e1);pe(e2);p(e3);
    if(v2 != (e1 + e2 + k2) / 2 || v3 != (e2 + e3 + k3) / 2 || (e1 + e2 + k2) % 2 == 1 || (e2 + e3 + k3) % 2 == 1){
        return false;
    }
    ll start = -1;
    if(i1 == i2){
        start = i1;
    }else if(e1 % 2 == 1){
        start = 0;
    }else if((e1 + e2) % 2 == 1){
        start = 1;
    }else if(e3 % 2 == 1){
        start = 3;
    }else{
        start = 2;
    }
    ll e[10];
    e[1] = e1, e[2] = e2, e[3] = e3;
    vector <ll> v;
    bool dame = false;
    ll now = start;
    while(1){
 
        v.pb(now);
        if(e[3] == 0 && e[1] == 0 && e[2] == 0){
            break;
        }
        if(now == 0){
            if(e[1] < 1){
                dame = true;
                break;
            }else{
                e[1] --;
                now = 1;
            }
        }else if(now == 1){
            if(e[1] >= 1){
                e[1] --;
                now = 0;
            }else if(e[2] >= 1){
                e[2] --;
                now = 2;
            }else{
                dame = true;
                break;
            }
        }else if(now == 2){
            if(e[3] >= 1){
                e[3] --;
                now = 3;
            }else if(e[2] >= 1){
                e[2] --;
                now = 1;
            }else{
                dame = true;
                break;
            }
        }else{
            if(e[3] >= 1){
                e[3] --;
                now = 2;
            }else{
                dame = true;
                break;
            }
        }
    }
    if(dame){
        return false;
    }else{
        p("YES");
        for(int i=0;i<v.size();i++){
            pe(v[i]);
        }
        el;
        return true;
    }
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
    cin >> v1 >> v2 >> v3 >> v4;
    n = v1 + v2 + v3 + v4;
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++){
            //pe(j);p(i);
            bool res = solve(j, i);
            if(res){
                return 0;
            }
        }
    }
    p("NO");
    
 
    return 0;
}