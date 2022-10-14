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
    vi v(n);
    forn(i, n){
      cin >> v[i];
    }
    if(v[n-1] == 3){
      cout << "-1\n";
      return 0;
    }
    vpi ans;
    vi two;
    vi three;
    int k = 1;
    forn(i, n){
      if(v[i] == 1){
        if(two.size() > 0){
          ans.pb(mp(two.back(), i+1));
          two.pop_back();
        }else if(three.size() > 0){
          ans.pb(mp(three.back(), i+1));
          ans.pb(mp(k, i+1));
          k++;
          three.pop_back();
        }else{
          ans.pb(mp(k, i+1));
          k++;
        }
      }else if(v[i] == 2){
        if(three.size() > 0){
          ans.pb(mp(three.back(), i+1));
          three.pop_back();

        }
        ans.pb(mp(k, i+1));
        two.pb(k);
        k++;
      }else if(v[i] == 3){
        if(three.size() > 0){
          ans.pb(mp(three.back(), i+1));
          three.pop_back();

        }
        ans.pb(mp(k, i+1));
        three.pb(k);
        k++;
      }
    }

    if(two.size() > 0 || three.size() > 0){
      cout << "-1\n";
      return 0;
    }
    cout << ans.size() << "\n";
    forn(i, ans.size()){
      cout << ans[i].f << " " << ans[i].s << "\n";
    }
    /*
    int one = 1;
    int hgt = n;
    bool down = false;
    forn(i, n){
      if(v[i] == 1){
        if(i < n-1){
          ans.pb(mp(i+1, one));
          one++;
        }else{
          ans.pb(mp(i+1, hgt));
          if(down){
            hgt--;
            ans.pb(mp(i+1, hgt));
          }
        }
        down = false;
      }else if(v[i] == 2){
        ans.pb(mp(i+1, hgt));
        if(down){
          hgt--;
          ans.pb(mp(i+1, hgt));
        }
        down = false;
      }else if(v[i] == 3){
        ans.pb(mp(i+1, hgt));
        if(down){
          hgt--;
          ans.pb(mp(i+1, hgt));
        }
        down = true;
      }
    }
    vi x(n+1);
    forn(i, ans.size()){
      x[ans[i].s-1]++;
    }
    forn(i, n){
      if(x[i] > 2){
        cout << "-1\n";
      }
      return 0;
    }

    forn(i, ans.size()){
      cout << n+1-ans[i].s << " " << ans[i].f << "\n";
    }*/
}