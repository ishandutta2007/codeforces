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

ll n,m,num,sum,a,b,c,d,e,h,q;
ll w, ans;
ll k;
ll l[500005], r[500005];
ll x[500005], y[500005], z[500005];
ll ansl[500005], ansr[500005];
char s[500005], t[500005];
ll st[500005];

void solve(){
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> x[i];
    }
    ll t = 0;
    for(ll i=0;i<n;i++){
        while(t > 0 && x[st[t - 1]] >= x[i]) t--;
        if(t == 0){
            l[i] = 0;
        }else{
            l[i] = st[t - 1] + 1;
        }
        st[t++] = i;
    }

    t = 0;
    for(ll i=n-1;i>=0;i--){
        while(t > 0 && x[st[t-1]] >= x[i]) t--;
        if(t == 0){
            r[i] = n;
        }else{
            r[i] = st[t - 1];
        }
        st[t++] = i;
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(l[i] == 0){
            ansl[i] = (i + 1) * x[i];
        }else if(x[i-1] < x[i]){
            ansl[i] = ansl[i-1] + x[i];
        }else{
            ansl[i] = ansl[l[i]-1] + x[i] * (i - l[i] + 1);
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(r[i] == n){
            ansr[i] = (n - i) * x[i];
        }else if(x[i] > x[i+1]){
            ansr[i] = ansr[i+1] + x[i];
        }else{
            ansr[i] = ansr[r[i]] + x[i] * (r[i] - i);
        }
    }
    ll idx = -1;
    for(ll i=0;i<n;i++){
        ll tmp = ansl[i] + ansr[i] - x[i];
        if(ans < tmp){
            idx = i;
            ans = tmp;
        }
    }

    y[idx] = x[idx];
    ll carry = x[idx];
    for(ll i=idx-1;i>=0;i--){
        carry = min(x[i], carry);
        y[i] = carry;
    }
    carry = x[idx];
    for(ll i=idx+1;i<n;i++){
        carry = min(x[i], carry);
        y[i] = carry;
    }
    for(ll i=0;i<n;i++){
        pe(y[i]);
    }
    el;

}


int main(){
    q = 1;
    while(q--){
        solve();
    }

    return 0;

}