#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
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
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<int> vi;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

int main(){
    int n;
    cin >> n;
    ll tot = 0;
    int ev = 0;
    forn(i,n){
        ll x;
        cin >> x;
        if(x>0){
            tot += x-1;
        }else if(x<0){
            tot += -1-x;
            ev += 1;
        }else{
            tot += 1;
            ev = -999999;
        }
    }
    if(ev > 0 && ev%2 == 1){
        tot += 2;
    }
    cout << tot << endl;
}