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
    int n;
    ll k;
    cin >> n >> k;
    vl v(n);
    forn(i,n){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    ll a, b;
    ll ai = 0;
    ll bi = n-1;
    while(k>0){
        if(ai==bi){
            cout << 0 << endl;
            return 0;
        }
        ll c1 = (ai+1)*(v[ai+1]-v[ai]);
        ll c2 = (n-bi)*(v[bi]-v[bi-1]);
        //cout << ai << " "  << bi << " " <<c1 << " " << c2 << " " << k<< endl;
        if(ai+1 < n-bi){
            if(c1<=k){
                k-=c1;
                ai++;
            }else{
                a = v[ai];
                a += k/(ai+1);
                b = v[bi];
                cout << b-a << endl;
                return 0;
            }
        }else if(ai+1 > n-bi){
            if(c2<=k){
                k-=c2;
                bi--;
            }else{
                a = v[ai];
                b = v[bi];
                b -= k/(n-bi);
                cout << b-a << endl;
                return 0;
            }
        }else{
            if(c1<=c2){
                if(c1<=k){
                    k-=c1;
                    ai++;
                }else{
                    a = v[ai];
                    a += k/(ai+1);
                    b = v[bi];
                    cout << b-a << endl;
                    return 0;
                }
            }else{
                if(c2<=k){
                    k-=c2;
                    bi--;
                }else{
                    a = v[ai];
                    a += k/(ai+1);
                    b = v[bi];
                    cout << b-a << endl;
                    return 0;
                }
            }
        }
    }
    cout << b-a << endl;
}