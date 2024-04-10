#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 1000008;
double Pi = 3.1415926535897932384626;
 
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
#define ps(x) cout<<fixed<<setprecision(8)<<x<<"\n";
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
ll mod1 = 2000000011;
ll mod2 = 2000000033;


ll rui1(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui1(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod1;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod1;
        }
        return number3;
    }
}

ll rui2(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui2(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod2;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod2;
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

void fast(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return;
}
 
ll n,m,num,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;
bool use[1000005];
string s, t;


struct LLRollingHash {
// long long RollingHash
public:
    ll n;
    ll base;
    ll mod;
    vector<ll> hash_table;
    vector<ll> base_pow;

    LLRollingHash(vector<ll> v, ll my_base, ll my_mod) {
        n = v.size();
        base = my_base;
        mod = my_mod;
        hash_table.resize(n + 1, 0ll);
        base_pow.resize(n + 1, 1ll);
        ll tmp = 0;
        for(ll i=0;i<n;i++){
            assert(v[i] >= 0);
            tmp = tmp * base + v[i];
            tmp %= mod;
            hash_table[i+1] = tmp;
        }
        for(ll i=0;i<n;i++){
            base_pow[i+1] = (base_pow[i] * base) % mod;
        }

    }

    ll hash(ll len, ll idx){
        // idxnHash
        if(len == 0)return 0ll;
        // assert(idx + len <= n);
        ll modpow = mod - base_pow[len];
        ll hash = (hash_table[len + idx] + (hash_table[idx] * modpow) % mod) % mod;
        return hash;
    }

    void add(ll val){
        n++;
        ll tmp = hash_table.back() * base + val;
        tmp %= mod;
        hash_table.pb(tmp);
        base_pow.pb((base_pow.back() * base) % mod);
        return;
    }
};

vector<ll> base_table = {128ll, 243ll, 125ll,
                         1340132568ll, 1025585316ll, 216ll};
vector<ll> mod_table =  {2000000011ll, 2000000033ll, 2000000063ll,
                         2147467057ll, 2147483353ll, 3000001811ll};



void solve(){
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    vector<ll> vs, vt;
    n = s.size();
    for(ll i=0;i<n;i++){
        ll a = s[i] - 'a';
        ll b = t[i] - 'a';
        vs.pb(a);
        vt.pb(b);
    }
    LLRollingHash rs(vs, 125, 2000000063ll);
    LLRollingHash rt(vt, 125, 2000000063ll);
    ll ans = 1;
    P t = P(1, 0);

    ll l, r;
    ll idxl, idxr;

    if(n == 1){
        p(s);
        return;
    }else if(n == 2){
        if(s[0] == s[1]){
            p(s);
        }else{
            p(s[0]);
        }
        return;
    }
    if(n % 2 == 0){
        l = n / 2 - 2;
        r = n - l - 1;
        if(s[l+1] == s[r-1]){
            idxl = r - 1;
            idxr = l + 1;
        }else{
            idxl = l + 1;
            idxr = r - 1;
        }
    }else{
        l = n / 2 - 1;
        r = n - 1 - l;
        idxl = l + 1;
        idxr = l + 1;
    }
    ll nl = l, nr = r;
    for(ll i=0;i<n;i++){
        use[i] = false;
    }
    for(ll i=0;i<n;i++){
        if(s[i] != s[n-1-i])break;
        use[i] = true;
    }
    for(ll i=0;i<n;i++){
        if(rs.hash(i + 1, 0) == rt.hash(i + 1, n - 1 - i)){
            if(ans < i + 1){
                ans = i + 1;
                t = P(i + 1, 0);
            }
        }
        if(rs.hash(n - i, i) == rt.hash(n - i, 0)){
            if(ans < n - i){
                ans = n - i;
                t = P(0, n - i);
            }
        }
    }
    if(use[l]){
        if(ans < idxl + 1 + n - r){
            ans = idxl + 1 + n - r;
            t = P(idxl + 1, n - r);
        }
    }
    while(1){
        if(s[l] == s[idxl + 1]){
            idxl ++;
        }else{
            while(1){
                if(rs.hash(idxl - l + 1, l) == rt.hash(idxl - l + 1, n - 1 - idxl))break;
                idxl--;
            }
        }
        l--;
        r++;
        if(ans < idxl + 1 + n - r && use[l]){
            ans = idxl + 1 + n - r;
            t = P(idxl + 1, n - r);
        }
        if(l <= 0)break;
    }
    l = nl, r = nr;
    if(use[l] && ans < l + 1 + n - idxr){
        ans = l + 1 + n - idxr;
        t = P(l + 1, n - idxr);
    }
    while(true){
        if(s[r] == s[idxr-1]){
            idxr--;
        }else{
            while(1){
                if(rs.hash(r - idxr + 1, idxr) == rt.hash(r - idxr + 1, n - 1 - r))break;
                idxr ++;
            }
        }
        l--;
        r++;
        if(ans < l + 1 + n - idxr && use[l]){
            ans = l + 1 + n - idxr;
            t = P(l + 1, n - idxr);
        }
        if(l <= 0)break;
    }
    p(s.substr(0, t.first) + s.substr(n - t.second, t.second));




    return;
}

int main(){
    // fast();
    ll q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}