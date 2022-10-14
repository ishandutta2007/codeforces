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
    int n;
    cin >> n;
    vector<lint> arr(n);
    forn(i,n){
        lint x;
        cin >> x;
        arr[i] = abs(x);
    }
    sort(arr.begin(),arr.end());
    int p1 = 0;
    lint tot = 0;
    for(int p2 = 1; p2<n; p2++){
        while(arr[p1]*2 < arr[p2]){
            p1++;
        }
        tot += p2-p1;
    }
    cout << tot;
}