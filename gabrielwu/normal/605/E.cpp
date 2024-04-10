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

int p[1000][1000];
double ex[1005];
double s[1005];
double res[1005];


int main(){
    fast_io();

    int n;
    cin >> n;
    forn(i,n){
        forn(j,n){
            cin >> p[i][j];
        }
    }

    fill(ex, ex+1000, 1e9);
    fill(res, res+1000, 1);
    fill(s, s+1000, 0);
    bitset<1000> done;

    ex[n-1] = 0;
    //printArr(ex,n);
    forn(cnt, n){
        double best = 1e8;
        int besti = -1;
        forn(i,n){
            if(!done.test(i) && ex[i] < best){
                best = ex[i];
                besti = i;
            }
        }

        done.set(besti);
        forn(i,n){
            if(!done.test(i) && p[i][besti] > 0){
                s[i] += res[i]*p[i][besti]/100.0*(best);
                res[i] *= (1-p[i][besti]/100.0);

                if(res[i] < .999){
                    ex[i] = (s[i]+1)/(1-res[i]);
                }
            }
        }
        if(besti == 0){
            cout << setprecision(16) << ex[0] << endl;
            return 0;
        }
        /*
        cout << besti << " -- \n";
        printArr(s,n);
        printArr(res,n);
        printArr(ex,n);
        */
    }
    //printArr(ex, n);

}