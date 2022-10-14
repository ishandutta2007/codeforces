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
    int n, m;
    cin >> n >> m;
    vi b;
    lint tot = 0;
    forn(i,n){
        lint x;
        cin >> x;
        b.pb(x);
        tot += x*m;
    }
    sort(b.begin(), b.end());
    //printVec(b);
    int it = n-1;
    int ch = 0;
    forn(i,m){
        int x;
        cin >> x;
        if(x == b[n-1]){
            continue;
        }
        if(x < b[n-1]){
            tot = -1;
            break;
        }
        if(ch == m-1){
            it--;
            //cout << "HI";
            //cout << b[it] << endl;
            ch = 1;
            tot += x-b[it];
        }else{
            ch++;
            //cout << b[it] << endl;
            tot += x-b[it];
        }
    }
    cout << tot << endl;
}