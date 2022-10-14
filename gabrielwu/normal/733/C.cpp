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
    vl a(n);
    readVec(a);
    int k;
    cin >> k;
    vl b(k);
    readVec(b);

    vi v;
    ll curr = 0;
    int ind = 0;
    int last = -1;
    vi ans;
    vector<char> dir;
    forn(i, n){
      if(ind >= k){
        cout << "NO\n";
        return 0;
      }
      curr += a[i];
      if(curr == b[ind]){
        v.pb(i-last);
        last = i;
        curr = 0;
        ind++;

      }else if(curr > b[ind]){
        cout << "NO\n";
        return 0;
      }
    }
    if(ind != k){
      cout << "NO\n";
      return 0;
    }

    //cout << a << b << v << "\n";
    int base = 0;
    int b2 = 0;
    for(int x: v){
      b2++;
      if(x == 1){
        base++;
        continue;
      }
      vl w;
      ll m = 0;
      for(int i=base; i<base+x; i++){
        w.pb(a[i]);
        if(a[i] > m){
          m = a[i];
        }
      }
      bool all = true;
      forn(i, x){
        all &= w[i]==m;
      }
      if(all){
        cout << "NO\n";
        return 0;
      }

      int choice = -1;
      bool left = false;
      if(w[0] == m && w[1] < m){
        choice = 0;
        left = false;
      }
      if(w[x-1] == m && w[x-2] < m){
        choice = x-1;
        left = true;
      }
      for(int i=1; i<x-1; i++){
        if(w[i] == m && w[i+1] < m){
          choice = i;
          left = false;
        }
        if(w[i] == m && w[i-1] < m){
          choice = i;
          left = true;
        }
      }
      int bx = x;
      if(left){
        ans.pb(choice+b2);
        dir.pb('L');
        x--;
        choice--;
      }else{
        ans.pb(choice+b2);
        dir.pb('R');
        x--;
      }
      forn(i, x-choice-1){
        ans.pb(choice+b2);
        dir.pb('R');
      }
      forn(i, choice){
        ans.pb(choice+b2-i);
        dir.pb('L');
      }
      base += bx;
    }

    cout << "YES\n";
    forn(i, ans.size()){
      cout << ans[i] << " " << dir[i] << "\n";
    }
}