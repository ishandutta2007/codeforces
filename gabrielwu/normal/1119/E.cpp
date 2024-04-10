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

int main(){
    fast_io();
    int n;
    cin >> n;
    vector<lint> v;
    forn(i,n){
        lint x;
        cin >> x;
        v.pb(x);
    }
    lint acc = 0;
    lint s = 0;
    for(int i=0; i<n; i++){
        lint d = min(v[i]/2,acc);
        acc -= d;
        v[i] -= 2*d;
        s += d;
        d = v[i]/3;
        v[i] -= 3*d;
        acc +=v[i];
        s+=d;
    }
    cout << s;
}