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
typedef vector<int> vi;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << endl;
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
    int n;
    cin >> n;
    vector<vector<bool> > adj(n,vector<bool>(n));
    vector<vi> fw(n,vi(n,INT_MAX));
    forn(i,n){
        forn(j,n){
            char c;
            cin >> c;
            if(c=='1'){
                adj[i][j] = true;
                fw[i][j] = 1;
            }else{
                adj[i][j] = false;
            }

        }
    }

    forn(i,n)
    {
        fw[i][i] = 0;
    }

    forn(k,n)
    {
        forn(i,n)
        {
            forn(j,n)
            {
                if(fw[i][k] != INT_MAX && fw[k][j] != INT_MAX && fw[i][k] + fw[k][j] < fw[i][j])
                {
                    fw[i][j] = fw[i][k] + fw[k][j];
                }
            }
        }
    }
    int m;
    cin >> m;
    vi p(m);
    forn(i,m){
        cin >> p[i];
        p[i]--;
    }
    vi v;
    v.pb(p[0]+1);
    int last = 0;
    for(int i=2; i<m; i++){
        if(i-last == fw[p[last]][p[i]]){
            continue;
        }else{
            v.pb(p[i-1]+1);
            last = i-1;
        }
    }
    v.pb(p[m-1]+1);

    cout << v.size() << endl;
    cout << v;

}