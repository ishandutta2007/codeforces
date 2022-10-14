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

typedef vector<int> vi;
typedef long long lint;

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

bool comp(pair<lint, lint> a, pair<lint, lint> b){
    return max(a.f,a.s) < max(b.f, b.s);
}

bool comp2(pair<lint, lint> a, pair<lint, lint> b){
    if(a.s == b.s){
        return a.f < b.f;
    }
    if(a.f == b.f){
        return a.s > b.s;
    }
    return a.s == max(b.f, b.s);
}

lint mdist(pair<lint, lint> a, pair<lint, lint> b){
    return llabs(a.f-b.f) + llabs(a.s-b.s);
}

int main(){
    int n;
    cin >> n;
    vector<pair<lint, lint> > v;
    forn(i,n){
        lint x, y;
        cin >> x >> y;
        v.pb(make_pair(x,y));
    }
    sort(v.begin(), v.end(), comp);
    vector<vector<pair<lint, lint> > > ends;
    int lvl = 0;
    int lvli = -1;
    forn(i,n){
        if(max(v[i].f,v[i].s) > lvl){
            lvl = max(v[i].f,v[i].s);
            lvli++;
            ends.pb(vector<pair<lint, lint> >());
            ends[lvli].pb(v[i]);
            ends[lvli].pb(v[i]);
        }else{
            if(comp2(v[i], ends[lvli][0])){
                ends[lvli][0] = v[i];
            }
            if(comp2(ends[lvli][1], v[i])){
                ends[lvli][1] = v[i];
            }
        }
    }


    lint dp[lvli+1][2];
    dp[0][0] = mdist(make_pair(0,0), ends[0][1]) + mdist(ends[0][0], ends[0][1]);
    dp[0][1] = mdist(make_pair(0,0), ends[0][0]) + mdist(ends[0][0], ends[0][1]);
    for(int i=1; i<=lvli; i++){
        dp[i][0] = min(mdist(ends[i-1][0], ends[i][1]) + dp[i-1][0],
                       mdist(ends[i-1][1], ends[i][1]) + dp[i-1][1]) + mdist(ends[i][0], ends[i][1]);
        dp[i][1] = min(mdist(ends[i-1][0], ends[i][0]) + dp[i-1][0],
                       mdist(ends[i-1][1], ends[i][0]) + dp[i-1][1]) + mdist(ends[i][0], ends[i][1]);
    }
    cout << min(dp[lvli][0], dp[lvli][1]) << endl;
    /*
    forn(i,lvli+1){
        cout << ends[i][0] << ends[i][1] << endl;
    }
    forn(i,lvli+1){
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    */
}