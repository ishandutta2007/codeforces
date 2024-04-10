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
    forn(it, t){
        int n;
        cin >> n;
        vector<bool> v(n,false);
        forn(i,n){
            char x;
            cin >> x;
            if(x=='1'){
                v[i] = true;
            }
        }
        int a, b, mid;
        a = n+1;
        b = -1;
        forn(i,n){
            if(v[i]){
                a = min(a,i);
                b = i;
            }
        }
        if(a==n+1){
            cout << n << endl;
        }else if(a==b){
            cout << max(n+1,max(a*2+2,(n-b)*2)) << endl;
        }else{
            mid = b-a;
            b = n-b;
            a++;
            cout << 2*max(a+mid, b+mid) << endl;
        }
    }
}