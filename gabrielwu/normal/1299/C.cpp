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
#define mp make_pair

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
  for(int i = 0; i < v.size(); i++) {printf("%.9f\n",v[i]);} return cout << "";
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

int n;
vl a;
vl prefix;
stack<pii> s;

ll sum(pii p){
    return prefix[p.s] - (p.f > 0 ? prefix[p.f-1] : 0);
}

bool worth(pii p1, pii p2){
    return sum(p1)*(p2.s-p2.f+1) >= sum(p2)*(p1.s-p1.f+1);
}

pii join(pii p1, pii p2){
    return make_pair(min(p1.f, p2.f),max(p1.s, p2.s));
}

int main(){
    fast_io();
    int n;
    cin >> n;
    a = vl(n);
    prefix = vl(n);
    forn(i,n){
        cin >> a[i];
    }
    prefix[0] = a[0];
    for(int i=1; i<n; i++){
        prefix[i] = a[i] + prefix[i-1];
    }
    forn(i,n){
        pii curr = mp(i,i);
        while(s.size() > 0 && worth(s.top(),curr)){
            curr = join(s.top(), curr);
            s.pop();
        }
        s.push(curr);
    }
    vector<double> ans(n);
    while(s.size() > 0){
        pii p = s.top();
        //cout << p << endl;
        s.pop();
        if(p.f == p.s){
            ans[p.f] = a[p.f];
        }else{
            double val = ((double) sum(p))/(p.s-p.f + 1);
            for(int i=p.f; i<= p.s; i++){
                ans[i] = val;
            }
        }
    }
    cout << ans;


}