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
    int n,h;
    cin >> n >> h;
    vi v;
    forn(i,n){

        int x;
        cin >> x;
        if(i==0 || x>=v[i-1]){
            v.pb(x);
        }else{
            vi::iterator it = v.begin();
            int ind = 0;
            while(x>v[ind]){
                it++;
                ind++;
            }
            v.insert(it,x);
        }
        int m=0;
        for(int j=i; j>=0; j-=2){
            m += v[j];
        }
        if(m>h){
            cout << i << endl;
            break;
        }else if(i==n-1){
            cout << n << endl;
            break;
        }
    }
}