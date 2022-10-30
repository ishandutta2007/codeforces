#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e17;
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


namespace NTT {
  void DFT(ll m, ll root, vector<ll> &a, bool rev = false) {
    ll N = a.size(), h = 0;
 
    for (ll i = 0; 1 << i < N; i++) h++;
    for (ll i = 0; i < N; i++) {
      ll j = 0;
      for (ll k = 0; k < h; k++)
        j |= (i >> k & 1) << (h - 1 - k);
      if (i < j) swap(a[i], a[j]);
    }
 
    for (ll i = 1; i < N; i *= 2) {
      ll base = rui(root, (m - 1) / i / 2);
      if (rev) base = rui(base, m - 2);
      ll w = 1;
      for (ll j = 0; j < i; j++) {
        for (ll k = 0; k < N; k += i*2) {
          ll s = a[j+k], t = a[j+k+i] * w % m;
          a[j+k+0] = (s + t) % m;
          a[j+k+i] = (s - t + m) % m;
        }
        w = w * base % m;
      }
    }
 
    if (rev) {
      ll tmp = rui(N, m-2);
      for(ll &v : a) v = v * tmp % m;
    }
  }
 
  //(1012924417, 5), (924844033, 5)
 
  vector<ll> conv(ll _mod, ll root, const vector<ll> &a, const vector<ll> &b) {
    ll s = 1, t = a.size() + b.size() - 1;
    while(s < t) s *= 2;
 
    vector<ll> F(s), G(s);
    for(ll i = 0; i < (ll)a.size(); i++) F[i] = a[i];
    for(ll i = 0; i < (ll)b.size(); i++) G[i] = b[i];
    DFT(_mod, root, F); DFT(_mod, root, G);
 
    for(ll i = 0; i < s; i++) F[i] = (ll)F[i] * G[i] % _mod;
    DFT(_mod, root, F, true);
 
    return F;
  }
};



ll n,m,num,sum,a,b,c,d,e,h,r,l,q;
ll k;
ll white[500005], red[500005];
ll ans[500005];
ll query[500005];

int main(){
    cin >> n >> k;
    c3_init();
    for(ll i=0;i<n;i++){
        cin >> white[i];
    }
    for(ll i=0;i<k;i++){
        cin >> red[i];
    }
    cin >> q;
    for(ll i=0;i<q;i++){
        cin >> query[i];
    }
    sort(white, white + n);
    reverse(white, white + n);
    ll cnt = 1;
    vector<P> table;
    for(ll i=0;i<n;i++){
        if(white[i] != white[i+1] || i == n - 1){
            table.pb(P(white[i], cnt));
            cnt = 1;
        }else{
            cnt ++;
        }
    }

    for(ll i=0;i<k;i++){
        ll a = 0, b = 0;
        for(ll j=0;j<table.size();j++){
            if(table[j].first >= red[i])continue;
            if(table[j].second >= 2)b++;
            if(table[j].second == 1)a++;
        }
        vector<ll> atable, btable;
        for(ll j=0;j<=a;j++){
            ll tmp = c3(a, j) * rui(2, j);
            tmp %= mod;
            atable.pb(tmp);
        }
        for(ll j=0;j<=2*b;j++){
            ll tmp = c3(2 * b, j);
            btable.pb(tmp);
        }
        auto res = NTT::conv(mod, 3ll, atable, btable);
        for(ll j=0;j<q;j++){
            ll cnt = query[j] / 2 - red[i] - 1;
            if(cnt < 0)continue;
            if(cnt > a + b * 2)continue;
            ans[j] += res[cnt];
            ans[j] %= mod;
        }
    }
    for(ll i=0;i<q;i++){
        p(ans[i]);
    }



    return 0;
}