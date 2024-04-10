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
  cout << "["; forn(i, v.size()){if(i) cout << ", "; cout << v[i]; } return cout << "]";
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
    string s;
    cin >> s;
    vi a(n, 1);
    forn(i, n-1){
      if(s.at(i)-'0'+a[i] == s.at(i+1)-'0'+a[i+1]){
        a[i+1]--;
      }
    }
    forn(i, n){
      cout << a[i];
    }cout << "\n";
  }
}