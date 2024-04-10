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

vector<string> getalts(string s, int k){
  vector<string> v;
  forn(i, 1<<k){
    string toadd = "";
    forn(j, k){
      if((i & (1<<j)) == 0){
        toadd += '_';
      }else{
        toadd += s.at(j);
      }
    }
    v.pb(toadd);
  }
  return v;
}

bool fits(string p, string s, int k){
  forn(i, k){
    if(!(p.at(i)=='_' || p.at(i)==s.at(i))) return false;
  }
  return true;
}

int main(){
    fast_io();
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<string, int> hm;
    vector<string> patterns(n);
    forn(i, n){
      string s;
      cin >> s;
      hm[s] = i+1;
      patterns[i] = s;
    }

    vii to(n);
    vi indeg(n);
    forn(i, m){
      string s;
      int mt;
      cin >> s >> mt;
      mt--;
      vi want;
      // cout << getalts(s, k) << endl;
      if(!fits(patterns[mt], s, k)){
        cout << "NO\n";
        return 0;
      }
      for(string alt: getalts(s, k)){
        if(hm[alt] > 0){
          want.pb(hm[alt]-1);
        }
      }
      for(int x: want){
        if(x != mt){
          to[mt].pb(x);
          indeg[x]++;
        }
      }
    }
    vi ans(n);
    vi avail;
    forn(i, n){
      if(indeg[i] == 0){
        avail.pb(i);
      }
    }
    forn(i, n){
      if(avail.empty()){
        cout << "NO\n";
        return 0;
      }
      ans[i] = avail.back();
      avail.pop_back();
      for(int x: to[ans[i]]){
        indeg[x]--;
        if(indeg[x] == 0){
          avail.pb(x);
        }
      }
    }
    cout << "YES\n";
    forn(i, n){
      cout << ans[i]+1 << " ";
    }cout << "\n";

}