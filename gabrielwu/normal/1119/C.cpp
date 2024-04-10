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
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    forn(i,n){
        forn(j,m){
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    forn(i,n){
        forn(j,m){
            int x;
            cin >> x;
            arr[i][j] = arr[i][j] != x;
        }
    }

    bool works = true;
    int cnt;
    forn(i,n){
        cnt = 0;
        forn(j,m){
            cnt += arr[i][j];
        }
        works = works && (cnt%2 == 0);
    }

    forn(j,m){
        cnt = 0;
        forn(i,n){
            cnt += arr[i][j];
        }
        works = works && (cnt%2 == 0);
    }

    if(works){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}