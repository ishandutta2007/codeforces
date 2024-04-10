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

 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;
ll ans;
ll x[500005], y[500005], z[200005];
char s[500005], t[500005];
string table[100];
bool used[500005];

vector<ll> base_table = {128ll, 243ll, 125ll,
                         1340132568ll, 1025585316ll, 216ll};
vector<ll> mod_table =  {2000000011ll, 2000000033ll, 2000000063ll,
                         2147467057ll, 2147483353ll, 3000001811ll};

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
        assert(idx + len <= n);
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
 
int main(){
    
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> s;
    ll base1 = base_table[0];
    ll mod1 = mod_table[0];
    ll base2 = base_table[1];
    ll mod2 = mod_table[1];
    ll n1 = strlen(s);
    vector<ll> v1;
    for(ll i=0;i<n1;i++){
        v1.pb(s[i]);
    }

    LLRollingHash s1(v1, base1, mod1);
    LLRollingHash s2(v1, base2, mod2);
    for(ll i=0;i<n-1;i++){
        cin >> t;
        ll n2;
        n2 = strlen(t);
        vector<ll> v2;
        for(ll j=0;j<n2;j++){
            v2.pb(t[j]);
        }
        LLRollingHash t1(v2, base1, mod1);
        LLRollingHash t2(v2, base2, mod2);
        ll len = min(n1, n2);
        for(ll j=len;j>=0;j--){
            ll hash1 = s1.hash(j, n1 - j);
            ll hash2 = t1.hash(j, 0);
            ll hash3 = s2.hash(j, n1 - j);
            ll hash4 = t2.hash(j, 0);
            if(hash1 == hash2 && hash3 == hash4){
                for(ll k=j;k<n2;k++){
                    v1.pb(v2[k]);
                    s1.add(v2[k]);
                    s2.add(v2[k]);
                }
                n1 += n2 - j;
                break;
            }
        }
    }
    ll n3 = v1.size();
    for(ll i=0;i<n3;i++){
        pu((char)(v1[i]));
    }
    el;
    return 0;
}