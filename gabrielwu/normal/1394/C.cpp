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

struct gem{
  int hor0, hor1, ver0, ver1, dia0, dia1;
  gem(int a, int b, int c, int d, int e, int f): hor0(a), hor1(b), ver0(c), ver1(d), dia0(e), dia1(f) {}
  gem(int x, int y, int dist){
    hor0 = x-dist;
    hor1 = x+dist;
    ver0 = y-dist;
    ver1 = y+dist;
    dia0 = y-x-dist;
    dia1 = y-x+dist;
  }

  gem merge(gem other){
    int a = max(hor0, other.hor0);
    int b = min(hor1, other.hor1);
    int c = max(ver0, other.ver0);
    int d = min(ver1, other.ver1);
    int e = max(dia0, other.dia0);
    int f = min(dia1, other.dia1);
    return gem(a, b, c, d, e, f);
  }

  pii valid(){
    vpi poss{{hor0, ver0}, {hor1, ver0}, {hor0, ver1}, {hor1,ver1}, {hor0, dia0+hor0}, {hor1, dia0+hor1}, {hor0, dia1+hor0}, {hor1, dia1+hor1}, {ver0-dia0, ver0}, {ver1-dia0, ver1}, {ver0-dia1, ver0}, {ver1-dia1, ver1}};
    for(auto p: poss){
      if(p.f >= 0 && p.s >= 0 && (p.s + p.f) > 0 && p.f >= hor0 && p.f <= hor1 && p.s >= ver0 && p.s <= ver1 && p.s-p.f >= dia0 && p.s-p.f <= dia1){
        return p;
      }
    }
    return mp(-1, -1);
    //return hor0 <= hor1 && ver0 <= ver1 && dia0 <= dia1;
  }

};
int main(){
    fast_io();
    int n;
    cin >> n;
    vpi v;
    forn(i, n){
      string s;
      cin >> s;
      int x=0, y=0;
      forn(i, s.size()){
        if(s.at(i) == 'B') x++;
        if(s.at(i) == 'N') y++;
      }
      v.pb(mp(x, y));
    }
    //cout << v << endl;
    pii ans;
    int lo = 0;
    int hi = 500000;
    while(lo < hi){
      int mid = (lo+hi)/2;
      gem g(v[0].f, v[0].s, mid);

      for(int i=1; i<n; i++){
        gem h(v[i].f, v[i].s, mid);
        //cout << "h " << h.hor0 << " " << h.hor1 << endl;
        g = g.merge(h);
        if(g.valid().f < 0){
          break;
        }
      }
      //cout << mid << " " << g.valid() << " FJDKS\n";
      //cout << "g " << g.hor0 << " " << g.hor1 << " " << g.ver0 << " " << g.ver1 << " "<< g.dia0 << " " << g.dia1 << endl;
      if(g.valid().f >= 0){
        hi = mid;
        ans = g.valid();
        //cout << g.hor0 << " " << g.hor1 << "g" << endl;
      }else{
        lo = mid+1;
      }
    }

    cout << lo << endl;
    forn(i, ans.f){
      cout << "B";
    }forn(i, ans.s){
      cout << "N";
    }cout << endl;


}