/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
#define MOD 998244353
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

bool compf(pair<int, int> a, pair<int, int> b){
    return a.f < b.f;//Your own function
}

bool comps(pair<int, int> a, pair<int, int> b){
    return a.s < b.s;//Your own function
}

bool compboth(pair<int, int> a, pair<int, int> b){
    if(a.f==b.f){
        return a.s < b.s;//Your own function
    }else{
        return a.f < b.f;//Your own function
    }
}

int main(){
    fast_io();
    int n;
    cin >> n;
    vpi v(n);
    forn(i,n){
        int x, y;
        cin >> x >> y;
        v[i] = make_pair(x,y);
    }

    ll way1 = 1, way2 = 1, both = 1, all = 1;

    vector<ll> fac(n+1);
    fac[0] = 1;
    fac[1] = 1;
    forn(i,n){
        all *= i+1;
        all %= MOD;
        fac[i+1] = all;
    }

    sort(v.begin(), v.end(), compboth);
    int lasti = 0, last = v[0].f;
    for(int i=1; i<n; i++){
        if(v[i].f > last){
            way1 *= fac[i-lasti];
            way1%=MOD;
            lasti = i;
            last = v[i].f;
        }
    }
    way1 *= fac[n-lasti];
    way1%=MOD;

    bool works = true;
    forn(i,n-1){
        if(v[i+1].s < v[i].s){
            works = false;
            break;
        }
    }
    if(works){
        lasti = 0;
        int last1 = v[0].f;
        int last2 = v[0].s;
        for(int i=1; i<n; i++){
            if(v[i].f > last1 || v[i].s > last2){
                both *= fac[i-lasti];
                both%=MOD;
                lasti = i;
                last1 = v[i].f;
                last2 = v[i].s;
            }
        }
        both *= fac[n-lasti];
        both%=MOD;
    }else{
        both = 0;
    }

    sort(v.begin(), v.end(), comps);
    lasti = 0;
    last = v[0].s;
    for(int i=1; i<n; i++){
        if(v[i].s > last){
            way2 *= fac[i-lasti];
            way2%=MOD;
            lasti = i;
            last = v[i].s;
        }
    }
    way2 *= fac[n-lasti];
    way2%=MOD;

    ll ans = all - way1 - way2 + both + MOD*2;
    ans %= MOD;
    cout << ans << endl;
}