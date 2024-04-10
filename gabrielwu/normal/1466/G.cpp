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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //use uniform_int_distribution<int>(0, i)(rng) if you want [0, i].
const ll P1 = MOD;
const ll P2 = 100663319LL;
const int p1 = uniform_int_distribution<int>(27, 20000)(rng);
const int p2 = uniform_int_distribution<int>(27, 20000)(rng);
const int MAXN = 3e6+5;
ll res1[MAXN];
ll res2[MAXN];
int main(){
    fast_io();
    res1[0] = 1;
    res2[0] = 1;
    for(int i=1; i<MAXN; i++){
      res1[i] = (res1[i-1]*p1)%P1;
      res2[i] = (res2[i-1]*p2)%P2;
    }
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    string z = s;
    int ind = 0;
    while(z.size() < 1000005 && ind<n){
      z = z+t.at(ind++)+z;
    }
    vl zhash1(z.size()), zhash2(z.size());
    zhash1[0] = z.at(0)-'a';
    zhash2[0] = z.at(0)-'a';
    for(int i=1; i<z.size(); i++){
      zhash1[i] = (zhash1[i-1]+(res1[i]*(z.at(i)-'a')))%P1;
      zhash2[i] = (zhash2[i-1]+(res2[i]*(z.at(i)-'a')))%P2;
    }
    vl zhashback1(z.size()), zhashback2(z.size());
    zhashback1[z.size()-1] = z.at(z.size()-1)-'a';
    zhashback2[z.size()-1] = z.at(z.size()-1)-'a';
    for(int i=z.size()-2; i>=0; i--){
      zhashback1[i] = (zhashback1[i+1]*p1+(z.at(i)-'a'))%P1;
      zhashback2[i] = (zhashback2[i+1]*p2+(z.at(i)-'a'))%P2;
    }
    //cout << "HI" << endl;
    vl shash1(s.size()), shash2(s.size());
    shash1[0] = s.at(0)-'a';
    shash2[0] = s.at(0)-'a';
    for(int i=1; i<s.size(); i++){
      shash1[i] = (shash1[i-1]+(res1[i]*(s.at(i)-'a')))%P1;
      shash2[i] = (shash2[i-1]+(res2[i]*(s.at(i)-'a')))%P2;
    }
    vl maxbranch(n+1);
    maxbranch[0] = s.size();
    for(int i=1; i<=n; i++){
      maxbranch[i] = min((ll)MOD, maxbranch[i-1]*2+1);
    }
    vl scnt(1000005);
    scnt[0] = 1;
    for(int i=1; i<1000005; i++){
      scnt[i] = (scnt[i-1]*2)%MOD;
    }

    vector<pair<int, pair<int, string> > > queries;
    forn(qi, q){
      int k;
      string w;
      cin >> k >> w;
      queries.pb(mp(qi, mp(k, w)));
    }
    sort(queries.begin(), queries.end(), [](auto a, auto b){return a.s.f < b.s.f;});
    vl answers(q);
    ll prevk = 0;
    vl letoc(26);
    for(pair<int, pair<int, string> > query: queries){
      int k = query.s.f;
      string w = query.s.s;

      for(int i=prevk+1; i<=k; i++){
        forn(j, 26){
          letoc[j] = (letoc[j]*2)%MOD;
        }
        if(i>20){
          letoc[t.at(i-1)-'a']++;
        }
      }
      prevk = k;


      int ws = w.size();
      if(ws > z.size()){
        cout << "     0\n";
        continue;
      }
      vb valid(ws, true);
      vl whash1(ws), whash2(ws);
      whash1[0] = w.at(0)-'a';
      whash2[0] = w.at(0)-'a';
      for(int i=1; i<ws; i++){
        whash1[i] = (whash1[i-1] + (w.at(i)-'a')*res1[i])%P1;
        whash2[i] = (whash2[i-1] + (w.at(i)-'a')*res2[i])%P2;
      }
      forn(i, ws-1){
        if(!(whash1[i] == zhashback1[z.size()-1-i] && whash2[i] == zhashback2[z.size()-1-i])){
          valid[i+1] = false;
        }
      }
      whash1[ws-1] = w.at(ws-1)-'a';
      whash2[ws-1] = w.at(ws-1)-'a';
      for(int i=ws-2; i>=0; i--){
        whash1[i] = (whash1[i+1]*p1 + (w.at(i)-'a'))%P1;
        whash2[i] = (whash2[i+1]*p2 + (w.at(i)-'a'))%P2;
      }
      for(int i=1; i<ws; i++){
        if(!(whash1[i] == zhash1[ws-1-i] && whash2[i] == zhash2[ws-1-i])){
          valid[i-1] = false;
        }
      }

      ll ans = 0;
      forn(i, ws){
        if(valid[i]){
          //cout << " ";
          ans = (ans+letoc[w.at(i)-'a'])%MOD;
          for(int j=0; j<min(k, 20); j++){
            if(t.at(j) == w.at(i) && i <= maxbranch[j] && ws-1-i <= maxbranch[j]){
              ans = (ans+scnt[k-j-1])%MOD;
            }
          }
          // ll occ = 1;
          // for(int j=k-1; j>=0; j--){
          //   if(t.at(j) == w.at(i) && i <= maxbranch[j] && ws-1-i <= maxbranch[j]){
          //     ans = (ans+occ)%MOD;
          //   }
          //   occ = (occ*2)%MOD;
          // }
        }
      }

      ll w1 = whash1[0];
      ll w2 = whash2[0];
      ll ins = 0;
      if(ws <= s.size()){
        for(int i=ws-1; i<s.size(); i++){
          if(shash1[i] == (w1+(i>=ws ? shash1[i-ws] : 0))%P1 && shash2[i] == (w2+(i>=ws ? shash2[i-ws] : 0))%P2){
            ins++;
          }
          w1 = (w1*p1)%P1;
          w2 = (w2*p2)%P2;
        }
      }
      ans = (ans + ins*scnt[k])%MOD;

      answers[query.f] = ans;
    }

    forn(qi, q){
      cout << answers[qi] << "\n";
    }
}