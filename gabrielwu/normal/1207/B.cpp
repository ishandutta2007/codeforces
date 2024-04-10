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

int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    vii a(n, vi(m));
    vii b(n, vi(m,0));
    forn(i,n){
        forn(j,m){
            cin >> a[i][j];
        }
    }

    int k = 0;
    vpi v;
    forn(i,n-1){
        forn(j,m-1){
            if(a[i][j] == 1){
                if(a[i+1][j]+a[i][j+1]+a[i+1][j+1] == 3){
                    k++;
                    v.pb(make_pair(i+1,j+1));
                    b[i][j] = 1;
                    b[i+1][j] = 1;
                    b[i+1][j+1] = 1;
                    b[i][j+1] = 1;
                }
            }
        }
    }

    bool flag = false;
    forn(i,n){
        forn(j,m){
            if(a[i][j] != b[i][j]){
                flag = true;
            }
        }
    }
    if(flag){
        cout << -1 << endl;
    }else{
        cout << k << endl;
        forn(i,k){
            cout << v[i].f << " " << v[i].s << endl;
        }
    }
}