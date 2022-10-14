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
    int n, k;
    cin >> n >> k;
    vi v;
    vi s;
    forn(i,n){
        int x;
        cin >> x;
        v.pb(x);
        if(i>0){
            s.pb(v[i]-v[i-1]);
        }
    }
    int ss = 0;
    sort(s.begin(), s.end());
    for(int i=0; i<k-1; i++){
        ss += s[s.size()-1-i];
    }
    cout << v[n-1]-v[0]-ss << endl;
}