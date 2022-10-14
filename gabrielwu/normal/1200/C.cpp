/**
TASK:
USER: gabriel90
LANG: C++
**/
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

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main(){
    //file_io();
    ll n, m;
    int q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    ll ns = n/g;
    ll ms = m/g;
    forn(qi, q){
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll sec1, sec2;
        if(sx == 1){
            sec1 = (sy-1)/ns;
        }else{
            sec1 = (sy-1)/ms;
        }
        if(ex == 1){
            sec2 = (ey-1)/ns;
        }else{
            sec2 = (ey-1)/ms;
        }
        if(sec2 == sec1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}