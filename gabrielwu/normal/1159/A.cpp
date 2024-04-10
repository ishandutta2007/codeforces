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
    int x = 0;
    int m = 0;
    forn(i,n){
        char c;
        cin >> c;
        if(c=='+'){
            x++;
        }else{
            x--;
            if(x<m){
                m = x;
            }
        }
    }
    cout << x-m << endl;
}