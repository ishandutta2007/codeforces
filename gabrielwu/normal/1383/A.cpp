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
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      string a, b;
      cin >> a >> b;


      //vb need(20), meed(20);
      //vector<vi> from(20);
      //vi cnt(20);
      bool works = true;
      vector<vi> reqs(20, vi(20));
      forn(i, n){

        if(a.at(i) < b.at(i)){
          //need[b.at(i)-'a'] = true;
          //need[a.at(i)-'a'] = true;
        //  meed[b.at(i)-'a'] = true;
          //from[b.at(i)-'a'].pb(a.at(i)-'a');
          //cnt[a.at(i)-'a']++;
          reqs[a.at(i)-'a'][b.at(i)-'a']++;
        }else if(a.at(i) > b.at(i)){
          works = false;
        }
      }
      if(works){
        /*
        int x = 0;
        forn(i, 20){
          if(need[i]) x++;
        }x--;cout << x << "\n";
        forn(i, 20){
          bool y = true;
          if(!need[i] || !meed[i]) continue;
          forn(j, from[i].size()-1){
            //cout << j << " " << from[i] << endl;
            if(from[i][j] != from[i][j+1]){
              y = false;
            }
          }
          if(y && from[i].size() == cnt[from[i][0]]){
            x--;
            //cout << i << " " << from[i] << endl;
          }
        }*/
        int x = 0;
        forn(i, 20){
          for(int j=i+1; j<20; j++){
            if(reqs[i][j] > 0){
              x++;
              for(int k=j+1; k<20; k++){
                reqs[j][k] += reqs[i][k];
              }
              break;
            }
          }
        }
        cout << x << "\n";
      }else{
        cout << "-1\n";
      }
    }
}