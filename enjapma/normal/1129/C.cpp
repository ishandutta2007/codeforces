#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 2e18;
const ll fact_table = 1200008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//,,,

#define endl "\n"
#ifdef ENJAPMA
    #undef endl
#endif
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
// const ll mod = 998244353ll;
const ll mod = 1000000007ll;
  
ll mypow(ll number1,ll number2, ll mod){
    if(number2 == 0){
        return 1ll;
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
void YES(bool condition){
    if(condition){ p("YES"); }else{ p("NO"); }
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
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    assert(n >= r);
    assert(n >= 0);
    assert(r >= 0);
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/
bool multicase = false;


double timeLimit=1.96;
const int64_t CYCLES_PER_SEC=2800000000;

struct Timer {
    int64_t start;
    Timer() { reset(); }
    void reset() { start = getCycle(); }
    inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
    inline int64_t getCycle() {
        uint32_t low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((int64_t)low) | ((int64_t)high << 32);
    }
};

Timer timer;

vector<ll> base_table = {128ll, 243ll, 125ll,
                         1340132568ll, 1025585316ll, 216ll};
vector<ll> mod_table =  {2000000011ll, 2000000033ll, 2000000063ll,
                         2147467057ll, 2147483353ll, 3000001811ll};

bool use_table[10];

struct LLRollingHash {
// long long RollingHash
public:
    ll n;
    ll base;
    ll mod;
    vector<ll> hash_table;
    vector<ll> base_pow;

    LLRollingHash(vector<ll> v, ll idx) {
        n = v.size();
        base = base_table[idx];
        mod = mod_table[idx];
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

ll n,m,num,a,b,c,d,e,q;
int dp[3005][3005];
string s;

bool valid(ll l, ll r){
    assert(r - l + 1 <= 4);
    if(r != l + 3)return true;
    if(s[l] == '0' && s[l+1] == '0' && s[l+2] == '1' && s[l+3] == '1')return false;
    if(s[l] == '0' && s[l+1] == '1' && s[l+2] == '0' && s[l+3] == '1')return false;
    if(s[l] == '1' && s[l+1] == '1' && s[l+2] == '1' && s[l+3] == '0')return false;
    if(s[l] == '1' && s[l+1] == '1' && s[l+2] == '1' && s[l+3] == '1')return false;
    return true;
}

void solve(){
    timer.reset();
    cin >> n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        cin >> a;
        s += (char)(a+'0');
        v.pb(a * 29ll + 11);
    }
    for(ll len=1;len<=n;len++){
        for(ll i=0;i+len-1<n;i++){
            ll l = i, r = i + len - 1;
            if(len <= 4){
                if(valid(l, r))dp[l][r] ++;
            }
            for(ll k=1;k<=4;k++){
                if(l > r - k)break;
                if(valid(r-k+1, r) && l <= r-k){
                    dp[l][r] += dp[l][r-k];
                    while(dp[l][r] >= mod)dp[l][r] -= mod;
                }
            }
        }
    }
    LLRollingHash Roll1(v, 0);
    LLRollingHash Roll2(v, 2);
    int ans = 0;
    unordered_set<ll> st11;
    st11.reserve(3000*1500); 
    ll ite = 0;
    for(ll r=0;r<n;r++){
        for(ll l=0;l<=r;l++){
            ite ++;
            if(ite % 100000 == 0){
                // pe("ite = ");p(ite / 10000);ps(timer.get());
            }
            ll hash1 = Roll1.hash(r - l + 1, l);
            ll hash2 = Roll2.hash(r - l + 1, l);
            hash1 = hash1 * 1000000000ll + hash2;
            if(st11.count(hash1))continue;
            st11.insert(hash1);
            ans += dp[l][r];
            if(ans >= mod)ans -= mod;
        }
        p(ans);
    }

    return;
}

int main(){
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, testcase = 1;
    if(multicase){
        cin >> q;
    }else{
        q = 1; 
    }
    while(q--){
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    // solve();
    return 0;
}