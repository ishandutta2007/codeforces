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
    vi arr;
    int k = 2147483647;
    forn(i,n){
        int x;
        cin >> x;
        if(n-1-i > 0){
            k = min(k, x/(n-1-i));
        }if(i>0){
            k = min(k, x/i);
        }
    }
    cout << k << endl;
}