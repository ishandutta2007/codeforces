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

int main(){
    ll x, n;
    cin >> x >> n;

    vl primes;
    ll num = 2;
    ll curr = x;
    ll last = 0;
    while(num*num <= x && curr > 1){
        if(curr%num==0){
            curr/=num;
            if(last != num){
                primes.pb(num);
                last = num;
            }
        }else{
            num++;
        }
    }
    if(curr > 1){
        primes.pb(curr);
    }
    //cout << primes << endl;

    ll tot = 1;
    for(ll p: primes){
        ll pcnt = 0;
        for(ll m=1; n/m >= p;){
            m*=p;
            pcnt += n/m;
        }
        //cout << p << " " << pcnt;

        ll val = p;
        while(pcnt>0){
            if(pcnt%2==1){
                tot *= val;
                tot %= MOD;
            }
            val *= val;
            val %= MOD;
            pcnt /= 2;
        }
    }
    cout << tot << endl;
}