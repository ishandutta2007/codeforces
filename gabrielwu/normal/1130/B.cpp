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
    cin >> n;
    int a[n];
    int b[n];
    forn(i,n){
        a[i] = -1;
        b[i] = -1;
    }
    forn(i,2*n){
        int x;
        cin >> x;
        x--;
        if(a[x] == -1){
            a[x] = i;
        }else{
            b[x] = i;
        }
    }
    int smaller = 0;
    int bigger = 0;
    long long total = 0;
    forn(i,n){
        total += abs(a[i]-smaller) + abs(b[i]-bigger);

        smaller = a[i];
        bigger = b[i];
    }
    cout << total;
}