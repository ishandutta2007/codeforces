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
    pii x = {1,1}, y={1,2};
    bool d = false;
    pii z;
    int f;
    while(!d){
      int a;
      cin >> a;
      if(a==2){
        cout << 1 << " " << x.f << " " << x.s << endl;
        x.s += 2;
        if(x.s > n){
          x.f++;
          x.s = (x.f%2 ? 1 : 2);
          if(x.f > n){
            d = true;
            z = y;
            f = 1;
          }
        }
      }else{
        cout << 2 << " " << y.f << " " << y.s << endl;
        y.s += 2;
        if(y.s > n){
          y.f++;
          y.s = (y.f%2 ? 2 : 1);
          if(y.f > n){
            d = true;
            z = x;
            f = 2;
          }
        }
      }
    }
    while(z.f <= n){
      int a;
      cin >> a;
      cout << (a==3 ? 3-f : 3) << " " << z.f << " " << z.s << endl;
      z.s += 2;
      if(z.s > n){
        z.f++;
        z.s = (f==2 ? (z.f%2 ? 1 : 2) : (z.f%2 ? 2 : 1));
      }
    }
}