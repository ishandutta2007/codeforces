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
    vi a(100), b(100);
    forn(i,100){
        a[i] = i;
        b[i] = (i+1)<<7;
    }
    cout << "? ";
    for(int i = 0; i < 100; i++) {if (i) cout << " "; cout << a[i];}
    cout << endl;
    fflush(stdout);

    int ans1;
    cin >> ans1;

    vi poss(100);
    forn(i,100){
        poss[i] = ans1 ^ a[i];
    }

    cout << "? ";
    for(int i = 0; i < 100; i++) {if (i) cout << " "; cout << b[i];}
    cout << endl;
    fflush(stdout);

    int ans2;
    cin >> ans2;
    int ans = -1;
    forn(i,100){
        int curr = ans2 ^ b[i];
        forn(j,100){
            if(curr == poss[j]){
                ans = curr;
            }
        }
    }
    cout << "! " << ans << endl;
    fflush(stdout);
}