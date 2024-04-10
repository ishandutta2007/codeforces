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


int main(){
    //file_io();
    int t;
    cin >> t;
    forn(ti, t){
        ll n, m, k;
        cin >> n >> m >> k;
        bool works = true;
        ll prev;
        cin >> prev;
        forn(i,n-1){
            ll x;
            cin >> x;
            if(prev+m+k >= x){
                m += min(prev, prev-x+k);
            }else{
                works = false;
            }
            //cout << " JKL" << prev << " " << x << " " << m << endl;
            prev = x;
        }
        if(works){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}