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
const ll mod = 2000000011;
  
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
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/

bool multicase = false;

ll n,m,num,a,b,c,d,e,h,q;
ll w, k, l, r;
char s[251][251];
ll producthash[251][251];
ll rhash[251][251];
int primes[27];
int manacher[510];
bool ispalind[251][251][251];
ll cnt[30];

void precalc(){
    ll idx = 0;
    for(ll i=53;;i+=4){
        bool isprime = true;
        for(ll j=2;j*j<=i;j++){
            if(i % j == 0)isprime = false;
        }
        if(isprime){
            primes[idx] = i;
            idx ++;
            if(idx == 26)break;
        }
    }

    for(ll i=0;i<n;i++){
        ll cnt = 1;
        producthash[i][0] = 1;
        for(ll j=0;j<m;j++){
            cnt *= primes[s[i][j] - 'a'];
            cnt %= mod;
            producthash[i][j+1] = cnt;
        }
        rhash[i][0] = 1;
        rhash[i][m] = mypow(producthash[i][m], mod - 2, mod);

        for(ll j=m-1;j>=1;j--){
            rhash[i][j] = rhash[i][j+1] * primes[s[i][j] - 'a'];
            rhash[i][j] %= mod;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<26;k++){
                cnt[k] = 0;
            }
            int dame = 0;
            for(ll k=j;k<m;k++){
                cnt[s[i][k]-'a']++;
                if(cnt[s[i][k]-'a'] % 2 == 1){
                    dame++;
                }else{
                    dame--;
                }
                ispalind[i][j][k] = dame < 2;
            }
        }
    }
    return;
}

ll calc(ll k, ll x, ll y){
    // k
    ll res = producthash[k][y+1] * rhash[k][x];
    res %= mod;
    return res;
}

void solve(){
    cin >> n >> m;
    for(ll i=0;i<n;i++){
        cin >> s[i];
    }
    precalc();

    vector<ll> v;
    ll ans = 0;
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            // [i, j] 

            v.clear();
            ll idx = -100;
            v.pb(-1);
            for(int k=0;k<n;k++){
                if(!ispalind[k][i][j]){
                    v.pb(idx);
                    idx --;
                }else{
                    v.pb(calc(k, i, j));
                }
                v.pb(-1);
            }
            int x = 0, y = 0;
            while(x < v.size()){
                while(x - y >= 0 && x + y < v.size() && v[x-y] == v[x+y])++y;
                manacher[x] = y;
                int k = 1;
                while(x-k >= 0 && k + manacher[x-k] < y){
                    manacher[x+k] = manacher[x-k];
                    k++;
                }
                x += k;
                y -= k;
            }
            for(int k=0;k<v.size();k++){
                if(v[k] < -30)manacher[k] = 0; 
                ans += manacher[k] / 2;
            }
        }
    }
    p(ans);
    return ;
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