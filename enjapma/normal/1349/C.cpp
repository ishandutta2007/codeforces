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
 
const ll mod = 998244353ll;
// const ll mod = 1000000007ll;
  
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
    assert(n >= r);
    assert(n >= 0);
    assert(r >= 0);
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/
bool multicase = false;


void init(){
    struct timeval _time;
    gettimeofday(&_time, NULL);
    ll usec = _time.tv_usec * 1000000;
    srand(usec);
    return;
}

ll range(ll a,ll b){
    //generate random number [a, b]
    ll num = rand() % (1 + b - a) + a;
    return num;
}

ll n,m,num,a,b,c,d,e,q, ans;
bool used[200005];
ll k;
string s[1005];
ll dp[1005][1005];
ll cost[1005][1005];
bool same[1005][1005];

void solve(){
    cin >> n >> m >> k;
    for(ll i=0;i<n;i++){
        cin >> s[i];
        for(ll j=0;j<m;j++){
            dp[i+1][j+1] = s[i][j] - '0' + 1;
        }
    }
    queue<P> que;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cost[i][j] = INF;
            bool flag = false;
            if(dp[i-1][j] == dp[i][j])flag = true;
            if(dp[i+1][j] == dp[i][j])flag = true;
            if(dp[i][j-1] == dp[i][j])flag = true;
            if(dp[i][j+1] == dp[i][j])flag = true;
            same[i][j] = flag;
            if(flag)que.push(P(i, j));
            if(flag)cost[i][j] = 0;
        }
    }
    while(que.size()){
        P p = que.front(); que.pop();
        for(int i=0;i<4;i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(1 <= nx && 1 <= ny && nx <= n && ny <= m && cost[nx][ny] == INF){
                que.push(P(nx, ny));
                cost[nx][ny] = cost[p.first][p.second] + 1;
            }
        }
    }
    for(ll i=0;i<k;i++){
        ll x, y, p;
        cin >> x >> y >> p;
        if(same[x][y]){
            ll now = dp[x][y] - 1;
            if(p % 2 == 1)now = 1 - now;
            p(now);
        }else{
            ll distance = cost[x][y];
            ll now = dp[x][y] - 1;
            if(p <= distance){
                p(now);
            }else{
                now = now + (p - distance) % 2;
                now %= 2;
                p(now);
            }
        }
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