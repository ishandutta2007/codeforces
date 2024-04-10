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
    int ind = 0;
    vi stack(n+5);
    int cnt = 0;
    //int cnt2 = 1;
    vector<pair<bool, int> > v(2*n);
    vi ans(n);
    forn(i, 2*n){
      char c;
      cin >> c;
      if(c=='+'){
        stack[ind++] = cnt++;
        v[i] = mp(false, -1);
      }

      else if(c=='-'){
        int x;
        cin >> x;
        if(ind == 0){
          cout << "NO" << "\n";
          return 0;
        }
        ans[stack[--ind]] = x;
        v[i] = mp(true, x);
      }
    }
    //cout << ans << endl;
    priority_queue<int, vi, greater<int> > pq;
    int x = 0;
    forn(i, 2*n){
      if(v[i].f == false){
        pq.push(ans[x]);
        x++;
      }else{
        int y = pq.top();
        pq.pop();
        if(y != v[i].s){
          cout << "NO\n";
          return 0;
        }
      }
    }
    cout << "YES\n";
    forn(i, n){
      cout << ans[i] << " ";
    }
}