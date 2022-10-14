/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
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

int main(){
    fast_io();
    int n;
    cin >> n;
    bool works = true;
    if(n%2 == 1){
        works = false;
    }
    vector<pii> a(n+1);
    forn(i,n){
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x,y);
    }
    a[n] = a[0];

    forn(i,n/2){
        pii v1 = make_pair(a[1+i].f-a[i].f, a[1+i].s-a[i].s);
        pii v2 = make_pair(a[i+n/2].f-a[i+n/2+1].f,a[i+n/2].s-a[i+n/2+1].s);
        if(!(v1.f == v2.f && v1.s == v2.s)){
            works = false;
        }
    }
    if(works){
        cout << "YES";
    }else{
        cout << "NO";
    }
}