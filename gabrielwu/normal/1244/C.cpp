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
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll a = p/w-1;// min(max((p-n*(w-d))/d - 5,ll(-1)),n);
    ll tried = 0;
    while(true){
        a++;
        tried++;
        if(a>n || tried > w-d+5){
            break;
        }
        if((p-a*d) % (w-d) == 0){
            ll x = (p-a*d)/(w-d);
            ll y = a-x;
            ll z = n-a;
            if(x>n || x<0 || y>n || y<0 || z>n || z<0){
                continue;
            }else{
                break;

            }
        }
    }

    if((p-a*d) % (w-d) == 0){
        ll x = (p-a*d)/(w-d);
        ll y = a-x;
        ll z = n-a;
        if(x>n || x<0 || y>n || y<0 || z>n || z<0){
            cout << -1 << endl;
        }else{
            cout << x << " " << y << " " << z << endl;

        }

    }else{
        cout << -1 << endl;
    }
}