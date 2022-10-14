#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define forn(i, n) for(int i=0; i<(n); i++)
#define pb push_back

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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> sols(100000*2,0);
    forn(i,n){
        cin >> v[i];
    }
    forn(i,n){
        for(int j=i+1; j<n; j++){
            sols[v[i] + v[j]]++;
        }
    }
    int m = 0;
    forn(i,sols.size()){
        if(sols[i] > m){
            m = sols[i];
        }
    }
    cout << m;
}