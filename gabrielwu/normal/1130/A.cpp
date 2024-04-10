/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define forn(i, n) for(int i=0; i<n; i++)

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
    int pos = 0;
    int neg = 0;
    cin >> n;

    forn(i,n){
        int x;
        cin >> x;
        if(x>0){
            pos++;
        }
        if(x<0){
            neg++;
        }
    }

    if(pos >= (n+1)/2){
        cout << 1;
    }else if(neg >= (n+1)/2){
        cout << -1;
    }else{
        cout << 0;
    }
}