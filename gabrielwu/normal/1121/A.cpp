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
    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    vector<vector<int> > schools;
    vector<int> power(n,-1);
    vector<bool> chosen(n,false);
    vector<int> v;
    forn(i,m){
        schools.pb(v);
    }
    forn(i,n){
        int x;
        cin >> x;
        power[i] = x;
    }
    forn(i,n){
        int x;
        cin >> x;
        schools[x-1].pb(i);
    }
    forn(i,k){
        int x;
        cin >> x;
        chosen[x-1] = true;
    }
    int total = k;
    forn(i,m){
        bool topChosen = false;
        int top = 0;
        forn(j,schools[i].size()){
            if(power[schools[i][j]] > top){
                topChosen = chosen[schools[i][j]];
                top = power[schools[i][j]];
            }
        }
        if(topChosen){
            total--;
        }
    }
    cout << total;
}