#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define pb push_back
#define mp make_pair
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
typedef vector<bool> vb;
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
    int t;
    cin >> t;
    forn(ti, t){
        ll n, s;
        cin >> n >> s;

        int without = 0;
        vi v(n);
        ll sc = s;
        forn(i,n){
            cin >> v[i];
        }

        forn(i,n){
            sc -= v[i];
            if(sc >= 0){
                without ++;
            }
        }
        sc = s;
        ll b = 0;
        int with = 0;
        int ind = -1;
        bool avail = true;
        forn(i,n){
            if(v[i] > b && avail){
                b = v[i];
                ind = i;
            }
            sc -= v[i];
            if(sc >= 0){
                with++;
            }else{
                if(avail){
                    sc += b;
                    avail = false;
                }
            }
        }

        if(with > without){
            cout << ind+1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}