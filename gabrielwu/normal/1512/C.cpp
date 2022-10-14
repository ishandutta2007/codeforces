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
      int a, b;
      cin >> a >> b;
      string s;
      cin >> s;
      int n = s.size();
      vector<char> v(n);
      forn(i, n) v[i] = s.at(i);
      bool works = true;
      forn(i, n){
        if(v[i]!='?'&&v[n-1-i]=='?')v[n-1-i] = v[i];
        if(v[i]!='?'&&v[n-1-i]!='?'&&v[i]!=v[n-1-i]){
          works = false;
        }
      }
      if(!works){
        cout << "-1\n";
        continue;
      }
      int doubles = 0;
      int curra = 0;
      forn(i, n){
        if(!(n%2==1 && i==n/2) && v[i] == '?' && v[n-1-i] == '?'){
          doubles++;
        }
        if(v[i] == '0')curra++;
      }
      doubles/=2;
      if(n%2==1 && v[n/2]=='?'){
        if((a-curra)%2 == 1) {v[n/2] = '0'; curra++;}
        else v[n/2] == '1';
      }
      if((a-curra)%2==0 && a>=curra && curra+doubles*2 >= a){
        forn(i, n){
          if(v[i] == '?'){
            if(a > curra){
              v[i] = '0'; v[n-1-i] = '0';
              curra+=2;
            }else{
              v[i] = '1'; v[n-1-i] = '1';
            }
          }
        }
        forn(i, n){
          cout << v[i];
        }
        cout << "\n";
      }else{
        cout << "-1\n";
      }
    }
}