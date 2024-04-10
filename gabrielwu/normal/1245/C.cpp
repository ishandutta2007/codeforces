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
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}

int main(){
    fast_io();
    string s;
    cin >> s;
    int n = s.size();
    vi v;
    char lc = ' ';
    int c = 0;
    ll res = 1;
    forn(i,n){
        if(s[i] == lc && (lc=='u' || lc=='n')){
            c++;
        }
        else{
            lc = s[i];
            v.pb(c);
            c = 1;
        }
        if(s[i] == 'm' || s[i] == 'w'){
            res = 0;
        }
    }
    v.pb(c);
    //cout << v;
    vl fib;
    fib.pb(1);
    fib.pb(1);
    for(int i = 2; i<=n; i++){
        fib.pb((fib[i-1]+fib[i-2])%MOD);
    }

    for(int i: v){
        res *= fib[i];
        res %= MOD;
    }
    cout << res << endl;


}