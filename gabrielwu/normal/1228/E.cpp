#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << endl;
}

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<vl> choose(n+1, vl(n+1));
    vl all(n+1), res(n+1);
    forn(i,n+1){
        forn(j,n+1){
            if(j==0){
                choose[i][j] = 1;
            }else if(i==0){
                choose[i][j] = 0;
            }else{
                choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
                choose[i][j] %= MOD;
            }
        }
    }
    all[0] = 1;
    res[0] = 1;
    for(int i=1; i<=n; i++){
        all[i] = all[i-1]*k;
        all[i] %= MOD;
        res[i] = res[i-1]*(k-1);
        res[i] %= MOD;
    }

    vector<vl> dp(n+1, vl(n+1,0));
    dp[0][0] = 1;
    forn(i,n){
        forn(j,n+1){
            dp[i+1][j] += dp[i][j]*((all[j]*res[n-j] - res[n])%MOD);
            dp[i+1][j] %= MOD;
            for(int k=j+1; k<=n; k++){
                dp[i+1][k] += dp[i][j]*((((all[j]*choose[n-j][k-j])%MOD) * res[n-k])%MOD);
                dp[i+1][k] %= MOD;
            }
        }
    }
    //cout << (-3) % 10 << endl;
    //cout << dp[n-3] << dp[n-2] << dp[n-1] << dp[n];
    cout << (dp[n][n]+MOD)%MOD << endl;
}