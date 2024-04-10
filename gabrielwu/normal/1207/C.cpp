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
    fast_io();
    int t;
    cin >> t;
    forn(casenum,t){
        ll n, a, b;
        cin >> n >> a >> b;
        ll cost = 0;
        cost += a*n;
        cost += b*(n+1);
        //cout << "DF" << cost << endl;
        string s;
        cin >> s;

        if(s.find("1") == s.npos){
            cout << cost << endl;
            continue;
        }

        vi z, o;
        int last = 0;
        z.pb(1);
        for(int i =1; i<n; i++){
            if(s[i]==last+'0'){
                if(last==0){
                    z[z.size()-1]++;
                }else{
                    o[o.size()-1]++;
                }
            }else{
                if(last==0){
                    last = 1;
                    o.pb(1);
                }else{
                    last = 0;
                    z.pb(1);
                }
            }
        }
        cost += 2*o.size()*a;
        //cout << "DF" << cost << endl;
        for(int i: o){
            cost += b*(i+1);
        }
        //cout << "DFF" << cost << endl;
        //cout << z << endl;
        //cout << o << endl;
        for(int i=1; i<z.size()-1; i++){
            if(b*(z[i]-1)-2*a < 0){
                cost += b*(z[i]-1)-2*a;
                //cout << "DF" << cost << endl;
            }
        }

        cout << cost << endl;
    }
}