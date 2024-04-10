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
    string s, p;
    cin >> s >> p;
    int n = s.size();
    int m = p.size();
    if(n<m){
      cout << 0 << "\n";
      return 0;
    }

    vi cnt(26);
    vi curr(26);
    for(char c: p){
      int x = c-'a';
      cnt[x]++;
    }
    int ans = 0;
    int bad = 0;
    for(int i=0; i<m; i++){
      char c = s.at(i);
      if(c!='?'){
        curr[c-'a']++;
      }
    }
    forn(i, 26){
      if(curr[i] > cnt[i]) bad++;
    }
    if(bad == 0){
      ans++;
    }
    forn(i, n-m){
      char c = s.at(m+i);
      if(c!='?'){
        if(curr[c-'a'] == cnt[c-'a']) bad++;
        curr[c-'a']++;
      }
      c = s.at(i);
      if(c!='?'){
        if(curr[c-'a'] == cnt[c-'a']+1) bad--;
        curr[c-'a']--;
      }
      if(bad == 0) ans++;
    }
    cout << ans << "\n";
}