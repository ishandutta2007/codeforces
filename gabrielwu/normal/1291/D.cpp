/**
https://codeforces.com/contest/1291/problem/D
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define pb push_back
#define mp make_pair
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

int pref[26][200005];

int main(){
    fast_io();

    string s;
    cin >> s;
    int q;
    cin >> q;


    forn(i,26){
        pref[i][0] = 0;
        forn(j,s.size()){
            pref[i][j+1] = pref[i][j] + (s[j]-'a'==i ? 1 : 0);
        }
    }

    forn(qi,q){
        int x,y;
        cin >> x >> y;
        if(y==x){
            cout << "Yes\n";
            continue;
        }
        int zs = 0;
        forn(i,26){
            if(pref[i][y]-pref[i][x-1] == 0){
                zs ++;
            }
        }
        if(zs >= 24){
            if(s[x-1]==s[y-1]){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }else{
            cout << "Yes\n";
        }
    }
    return 0;
}