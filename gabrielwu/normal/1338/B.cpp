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


int main(){
    fast_io();
    int n;
    cin >> n;
    vector<vi> adj(n);
    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    vb leaf(n);
    int root;
    forn(i, n){
        if(adj[i].size() == 1){
            leaf[i] = true;
            root = i;
        }
    }
    //cout << leaf << endl;
    //cout << adj << endl;
    int biggest = n-1;
    forn(i, n){
        int lc = 0;
        for(int u: adj[i]){
            if(leaf[u]){
                lc++;
            }
        }
        if(lc > 1){
            biggest -= (lc-1);
        }
        //cout << "lc " << lc << endl;
    }
    int smallest = 1;
    vb visited(n);
    vi dist(n);
    vi visit;
    visit.pb(root);
    visited[root] = true;
    int x = 1;
    while(visit.size() > 0){
        vi visitNext;
        for(int u: visit){
            for(int v: adj[u]){
                if(!visited[v]){
                    dist[v] = x;
                    visitNext.pb(v);
                    visited[v] = true;
                }
            }
        }
        visit = visitNext;
        x++;
    }
    forn(i, n){
        if(leaf[i] && dist[i]%2==1){
            smallest = 3;
        }
    }
    //cout << dist << endl;
    cout << smallest << " " << biggest << endl;

}