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
    int n, m;
    cin >> n >> m;
    vector<vi> edges(n,vi());
    vpi prs;
    forn(i,m){
        int a, b;
        cin >> a >> b;
        edges[a-1].pb(b-1);
        edges[b-1].pb(a-1);
        prs.pb(make_pair(a-1,b-1));
    }

    vi g1, g2, g3;
    vector<bool> taken(n,false);
    vector<int> g(n,0);
    bool works = true;
    for(int v: edges[0]){
        taken[v] = true;
    }
    forn(i,n){
        if(!taken[i]){
            g1.pb(i);
            g[i] = 1;
        }
        taken[i] = false;
    }

    //cout << g1;

    int s = 0;
    while(g[s] != 0){
        s++;
        if(s==n){
            cout << -1 << endl;
            return 0;
        }
    }

    for(int v: edges[s]){
        taken[v] = true;
    }
    forn(i,n){
        if(!taken[i]){
            g2.pb(i);
            g[i] = 2;
        }
        taken[i] = false;
    }

    //cout << g2;
    s = 0;
    while(g[s] != 0){
        s++;
        if(s==n){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int v: edges[s]){
        taken[v] = true;
    }
    forn(i,n){
        if(!taken[i]){
            g3.pb(i);
            g[i] = 3;
        }
        taken[i] = false;
    }
    //cout << g3;

    ll expected = g1.size()*(g2.size()+g3.size()) + g2.size()*(g1.size() + g3.size()) + g3.size()*(g1.size()+g2.size());
    if(m*2 != expected || g1.size()+g2.size()+g3.size() != n){
        cout << -1 << endl;
        return 0;
    }

    for(auto p: prs){
        if(g[p.f] == g[p.s]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << g;
}

/*
6 11
1 2
1 3
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6

4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/