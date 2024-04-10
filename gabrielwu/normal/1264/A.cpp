/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
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
typedef vector<bool> vb;
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
    forn(ti, t){
        int n;
        cin >> n;
        vi v;
        int before = -1;
        int cnt = 0;
        forn(i,n){
            int x;
            cin >> x;
            if(x < before){
                v.pb(cnt);
                cnt = 0;
            }
            before = x;
            cnt++;
        }
        v.pb(cnt);

        int g = v[0];
        int s = 0, b = 0;
        int i = 1;
        bool bad = false;
        while(s<=g){
            if(i>=n){
                bad = true;
                break;
            }
            s += v[i];
            i++;
        }
        if(bad){
            cout << "0 0 0" << endl;
            continue;
        }
        while(true){
            if(i>=n){
                bad = true;
                break;
            }
            if((g+s+b+v[i])*2 > n){
                break;
            }
            b += v[i];
            i++;
        }
        if(bad){
            cout << "0 0 0" << endl;
            continue;
        }

        if((g+s+b)*2 > n || b<=g){
            cout << "0 0 0" << endl;
            continue;
        }
        cout << g << " " << s << " " << b << " " << endl;

    }
}