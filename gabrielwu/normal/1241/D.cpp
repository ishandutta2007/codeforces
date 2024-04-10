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
    int q;
    cin >> q;
    forn(qi,q){
        int n;
        cin >> n;
        vector<pair<int, int> > v(n,make_pair(n,-1));
        int cnt = 0;
        int sm = n+1;
        forn(i,n){
            int x; cin >> x;
            x--;
            if(v[x].s ==-1){
                cnt++;
            }
            v[x].f = min(v[x].f,i);
            v[x].s = i;
            sm = min(sm,x);
        }
        int longest = 1;
        int curr = 1;
        int before = sm;
        for(int i=sm+1; i<n; i++){
            if(v[i].s >= 0){
                if(v[i].f > v[before].s){
                    curr +=1;
                }else{
                    curr = 1;
                }
                before = i;
            }
            longest = max(longest,curr);
        }

        cout << cnt-longest << endl;
    }

}