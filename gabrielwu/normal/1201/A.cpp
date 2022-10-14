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
    int n, m;
    cin >> n >> m;
    vector<vi> answers(m, vi(5,0));
    vi weights(m);
    forn(i,n){
        forn(j,m){
            char x;
            cin >> x;
            answers[j][x-'A']++;
        }
    }
    forn(i,m){
        cin >> weights[i];
    }
    int tot = 0;
    forn(i,m){
        int most = 0;
        forn(j,5){
            most = max(most, answers[i][j]);
        }
        tot += weights[i]*most;
    }
    cout << tot << endl;

}