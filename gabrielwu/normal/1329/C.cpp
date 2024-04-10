#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
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
  for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << "";
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

vl v;
int h, g;
ll s;

int ending_depth(int i, int d){
    while(d<h){
        if(v[2*i] + v[2*i+1] == 0){
            return d;
        }
        if(v[2*i] > v[2*i+1]){
            return ending_depth(2*i, d+1);
        }
        return ending_depth(2*i+1, d+1);
    }
}

void f(int i, int d){
    if(d == h){
        v[i] = 0;
        return;
    }
    if(v[2*i] + v[2*i+1] == 0){
        v[i] = 0;
        return;
    }
    if(v[2*i] > v[2*i+1]){
        v[i] = v[2*i];
        f(2*i, d+1);
    }else{
        v[i] = v[2*i+1];
        f(2*i+1, d+1);
    }
}

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
        cin >> h >> g;
        v = vl(1<<h);
        s = 0;
        forn(i, (1<<h)-1){
            cin >> v[i+1];
            s += v[i+1];
        }

        vi ops;

        int depth = 1;
        for(int i=1; i<=(1<<g)-1; i++){
            if(i >= (1<<depth)){
                depth++;
            }
            while(ending_depth(i, depth) > g){
                s -= v[i];
                ops.pb(i);
                f(i, depth);

            }
        }


        cout << s << endl;
        cout << ops << endl;

    }
}