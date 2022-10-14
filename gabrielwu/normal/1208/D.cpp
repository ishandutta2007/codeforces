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
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << endl;
}

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

//Can be treated by user as 0-indexed, but the this.tree is 1-indexed.
//Thus, it adds 1 to i and j after it receives them.
struct BIT{
    vector<ll> tree;

    BIT(int length):tree(length+1,0){}

    BIT(vector<int> v):BIT(v.size()){
        forn(i,v.size()){
            add(i,v[i]);
        }
    }
    void add(int i, ll val){
        i++;
        while(i<tree.size()){
            tree[i] += val;
            i += i&-i;   //Add last set bit
        }
    }
    void setVal(int i, ll val){
        add(i,val-sum(i,i));
    }
    ll sum(int i){
        i++;
        ll total = 0;
        while(i>0){
            assert(i<(tree.size()));
            total += tree[i];
            i -= i&-i;   //Subtract last set bit
        }
        return total;
    }

    int sum(int a, int b){
        return sum(b) - sum(a-1);
    }

};


int main(){
    int n;
    cin >> n;
    vl v(n), u(n);
    forn(i,n){
        cin >> v[i];
    }

    BIT b(n+1);
    forn(i,n+1){
        b.add(i,i);
    }

    for(int i=n-1; i>=0; i--){
        int lo = 1;
        int hi = n;
        while(hi > lo+1){
            int mid = (lo+hi)/2;
            ll x = b.sum(mid-1);
            if(x>v[i]){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        if(b.sum(hi-1)==v[i]){
            u[i] = hi;
            b.setVal(hi,0);
        }else{
            u[i] = lo;
            b.setVal(lo,0);
        }
    }

    cout << u;
}