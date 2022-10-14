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
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    int n = s.size();

    vector<char> v(n);
    ll tot0=0, tot1=0;
    forn(i, n){
      v[i] = s.at(i);
      if(v[i] == '1'){
        tot1++;
      }else{
        tot0++;
      }
    }
    ll score = 0;
    ll cur0 = 0, cur1 = 0;
    forn(i, n){
      if(v[i]=='1'){
        cur1++;
        score +=  y*(tot0 - cur0);
      }else{
        cur0++;
        score += x*(tot1 - cur1);
      }
    }

    ll best = score;
    cur0 = 0;
    cur1 = 0;
    ll curq = 0;
    forn(i, n){
      if(v[i]=='1'){
        cur1++;
      }else if(v[i]=='0'){
        cur0++;
      }else if(v[i]=='?'){

        score -= y*(cur1+curq);
        score += y*(tot0-cur0-curq-1);
        score += x*(cur0);
        score -= x*(tot1-cur1);
        best = min(score, best);
        curq++;
      }
    }
    //cout << "BEST " << best << "\n";
    //DIFIVJOISFJ EWFHWGE
    score = 0;
    cur0 = 0; cur1 = 0;
    for(int i=n-1; i>=0; i--){
      if(v[i]=='1'){
        cur1++;
        score +=  x*(tot0 - cur0);
        //cout << "Sc " << score << "\n";
      }else{
        cur0++;
        score += y*(tot1 - cur1);
      }
    }
    best = min(best, score);
    //cout << "HI " << best << "\n";
    cur0 = 0;
    cur1 = 0;
    curq = 0;
    for(int i=n-1; i>=0; i--){
      if(v[i]=='1'){
        cur1++;
      }else if(v[i]=='0'){
        cur0++;
      }else if(v[i]=='?'){
        score -= x*(cur1+curq);
        score += x*(tot0-cur0-curq-1);
        score += y*(cur0);
        score -= y*(tot1-cur1);
        best = min(score, best);
        curq++;
      }
    }

    cout << best << "\n";

}