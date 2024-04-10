#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A> ostream& operator<<(ostream& cout, vector<A> const& v){
  cout << "["; forn(i, v.size()){if(i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> ostream& operator<<(ostream& cout, pair<A, B> const& p){
  return cout << "(" << p.f << ", " << p.s << ")";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  forn(ti, t){
    int n;
    cin >> n;
    vi v(2*n);
    forn(i, 2*n){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    // cout << v << "\n";
    bool done = false;
    for(int a=0; a<2*n-1; a++){
      multiset<int> s;
      forn(i, 2*n){
        s.insert(v[i]);
      }
      int x = v[2*n-1] + v[a];
      //cout << "x " << x << endl;
      int init = x;
      vector<pii> ans;
      bool works = true;
      forn(i, n){
        int need = x - *(s.rbegin());
        // cout << "need " << need << "\n ";
        // cout << *(s.rbegin()) << " big \n";
        // for(int d: s){
        //   cout << d << " ";
        // }
        if(s.find(need) != s.end() && s.find(need) != --s.end()){
          ans.pb(mp(need, *(s.rbegin())));
          x = *(s.rbegin());

          s.erase(--s.end());
          s.erase(s.find(need));
        }else{
          // cout << "quit\n";
          works = false;
          break;
        }
      }
      if(works){
        done = true;
        cout << "YES\n";
        cout << init << "\n";
        for(pii p: ans){
          cout << p.f << " "<<p.s << "\n";
        }
        break;
      }
    }
    if(!done){
      cout << "NO\n";
    }
  }
}