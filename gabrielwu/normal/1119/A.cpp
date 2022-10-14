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
    vi v;
    forn(i,n){
        int x;
        cin >> x;
        v.pb(x);
    }
    if(v[0] != v[n-1]){
        cout << n-1 << endl;
    }else{
        int m = 0;

        forn(i,n){
            if(v[i] != v[n-1]){
                m = n-1-i;
                break;
            }
        }
        forn(i,n){
            if(v[0] != v[n-1-i]){
                m = max(n-1-i,m);
                break;
            }
        }
        cout << m << endl;
    }
}