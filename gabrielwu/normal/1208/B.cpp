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

struct Bounds{
    int a, b, c, d;
    Bounds(): Bounds(-1){}
    Bounds(int e): a(e),b(e),c(e),d(e){}

    void add(int e){
        if(a==b){
            b=e;
            d=e;
        }else{
            c=d;
            d=e;
        }
    }
    string ts(){
        return "(" + to_string(a) + " " + to_string(b) + " " + to_string(c) + " " + to_string(d) + ")";
    }
};
int main(){
    fast_io();
    int n;
    cin >> n;
    vi v(n);
    vi u(n,-1);
    forn(i,n){
        cin >> v[i];
    }

    map<int, Bounds> m;
    forn(i,n){
        if(m.find(v[i])==m.end()){
            m[v[i]] = Bounds(i);
        }else{
            m[v[i]].add(i);
        }
    }
    /*
    for(auto p:m){
        cout << p.f << " " << p.s.ts() << endl;
    }*/
    forn(i,n){
        for(auto p: m){
            if(p.s.a == p.s.b){
                continue;
            }
            if(p.s.a >= i){
                u[i] = max(u[i],p.s.c);
            }else if(p.s.b >= i){
                u[i] = max(u[i],p.s.d);
            }else{
                u[i] = INT_MAX;
            }
        }
        //cout << i << " " << u[i] << endl;
    }
    int best = INT_MAX;
    forn(i,n){
        best = min(best, max(u[i]-i+1,0));
    }
    cout << best << endl;


}