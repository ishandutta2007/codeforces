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

int takeout(int x, int pos){
    return x-((x/pos)%10)*pos;
}


int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
        int n;
        cin >> n;
        vi v(n);
        forn(i,n){
            cin >> v[i];
            //cout << v[i];
        }
        int tot = 0;
        forn(i,n){
            bool in = false;
            forn(j,i){
                if(v[j] == v[i]){
                    in = true;
                    break;
                }
            }
            if(in){
                tot++;
                vi guesses;
                forn(d, 10){
                    guesses.pb(takeout(v[i],1)+d);
                }
                forn(d, 10){
                    guesses.pb(takeout(v[i],10)+d*10);
                }
                forn(d, 10){
                    guesses.pb(takeout(v[i],100)+d*100);
                }
                forn(d, 10){
                    guesses.pb(takeout(v[i],1000)+d*1000);
                }
                bool done = false;
                for(int guess: guesses){
                    in = false;
                    forn(j,n){
                        if(v[j] == guess){
                            in = true;
                            break;
                        }
                    }
                    if(!in){
                        v[i] = guess;
                        break;
                    }
                }
            }

        }
        cout << tot << endl;
        forn(i,n){
            if(v[i]<1000){
                cout << 0;
            }
            if(v[i]<100){
                cout << 0;
            }
            if(v[i]<10){
                cout << 0;
            }
            cout << v[i] << endl;
        }
    }
}