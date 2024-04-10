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
    vi cnt(26,0);
    int n;
    cin >> n;
    forn(i,n){
        string x;
        cin >> x;
        cnt[(int)x[0] - (int)'a']++;
    }
    int tot = 0;
    forn(i,26){
        int a = cnt[i]/2;
        int b = cnt[i] - a;
        tot += a*(a-1)/2 + b*(b-1)/2;
    }
    cout << tot;
}