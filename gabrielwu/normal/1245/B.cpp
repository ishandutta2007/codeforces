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

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        vi v(n);
        forn(i,n){
            char x;
            cin >> x;
            if(x=='R'){
                v[i] = 0;
            }else if(x=='P'){
                v[i] = 1;
            }else if(x=='S'){
                v[i] = 2;
            }
        }
        vi out(n,-1);
        int wins = 0;
        forn(i,n){
            if(v[i]==0){
                if(b>0){
                    b--;
                    out[i] = 1;
                    wins++;
                }
            }else if(v[i]==1){
                if(c>0){
                    c--;
                    out[i] = 2;
                    wins++;
                }
            }else if(v[i] == 2){
                if(a>0){
                    a--;
                    out[i] = 0;
                    wins++;
                }
            }
        }

        forn(i,n){
            if(out[i] == -1){
                if(a>0){
                    out[i]  = 0;
                    a--;
                }else if(b>0){
                    out[i] = 1;
                    b--;
                }else{
                    out[i] = 2;
                }

            }
        }
        if(wins*2>=n){
            cout << "YES" << endl;
            forn(i,n){
                if(out[i]==0){
                    cout << "R";
                }else if(out[i]==1){
                    cout << "P";
                }else{
                    cout << "S";
                }
            }cout << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}