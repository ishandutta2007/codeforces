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
ll x[100005], y[500005], z[200005];

ll query_level[50][1040][3][3];
bool dp[50][1040][3][3];
char s[500005];
ll use[500005];
ll query;
 
 
bool rec(ll idx, ll bit, bool flag, ll next){
    if(query_level[idx][bit][flag][next] == query){
        return dp[idx][bit][flag][next];
    }
    ll digit = s[idx] - '0';
    if(idx == -1){
        if(bit == 0){
            query_level[idx][bit][flag][next] = query;
            dp[idx][bit][flag][next] = true;
            return true;
        }else{
            query_level[idx][bit][flag][next] = query;
            dp[idx][bit][flag][next] = false;
            return false;
        }
    }
    if(next){
        bool res = rec(idx - 1, bit ^ (1ll << 0), false, next - 1);
        if(res){
            use[idx] = 0;
            query_level[idx][bit][flag][next] = query;
            dp[idx][bit][flag][next] = true;
            return true;
        }
    }
    if(flag){
        bool res = rec(idx - 1, bit ^ (1ll << digit), true, 0);
        if(res){
            use[idx] = digit;
            query_level[idx][bit][flag][next] = query;
            dp[idx][bit][flag][next] = true;
            return true;
        }
        for(ll i=digit - 1;i>=0;i--){
            bool res = rec(idx - 1, bit ^ (1ll << i), false, 0);
            if(res){
                use[idx] = i;
                dp[idx][bit][flag][next] = true;
                query_level[idx][bit][flag][next] = query;
                return true;
            }
        }
    }else{
        for(ll i=9;i>=0;i--){
            bool res = rec(idx - 1, bit ^ (1ll << i), false, 0);
            if(res){
                use[idx] = i;
                query_level[idx][bit][flag][next] = query;
                dp[idx][bit][flag][next] = true;
                return true;
            }
        }
    }

    query_level[idx][bit][flag][next] = query;
    return false;
}

void sub(ll idx){
    if(s[idx] == '0'){
        s[idx] = '9';
        sub(idx - 1);
    }else{
        s[idx]--;
    }
    return ;
}


void print(ll flag){
    if(flag){
        for(ll i = n - 3;i>=0;i--){
            pu(use[i]);
        }
        el;
        return;
    }
    for(ll i=min(12ll, n-1);i>=0;i--){
        pu(use[i]);
    }
    el;
    return;
}
 
void solve(ll n){
    n = n;
    ll bit = 0;
    sub(n - 1);
    reverse(s, s + n);
    bool corner = false;
    ll digitcut = 13;
    ll idx = 0;
    for(ll i=n-1;i>=digitcut;i--){
        bit = bit ^ (1ll << (s[i] - '0'));
        z[idx++] = s[i] - '0';
    }
    bool res = rec(min(n - 1, digitcut - 1), bit, true, 0);
    for(ll i=min(digitcut-1, n-1);i>=0;i--){
        z[idx++] = use[i];
    }
    if(z[0] == 0){
        // cornercase
        for(ll i=0;i<n-2;i++){
            s[i] = '9';
        }
        bit = 0;
        idx = 0;
        n -= 2;
        for(ll i=n-1;i>=digitcut;i--){
            bit = bit ^ (1ll << (s[i] - '0'));
            z[idx++] = s[i] - '0';
        }
        bool res = rec(min(n-1, digitcut-1), bit, true, 0);
        for(ll i=min(digitcut-1, n-1);i>=0;i--){
            z[idx++] = use[i];
        }
        for(ll i=0;i<idx;i++){
            pu(z[i]);
        }
        el;
    }else{
        for(ll i=0;i<idx;i++){
            pu(z[i]);
        }
        el;
        return;
    }

    
    return;
}
 
int main(){
    /*
    cin.tie(0);
    ios::sync_with_stdio(false);
    */
    cin >> q;
    for(ll i=0;i<q;i++){
        query++;
        cin >> s;
        n = strlen(s);
        solve(n);
    }
    return 0;
}