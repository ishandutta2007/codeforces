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

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<int> vi;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}


int n, k;
bool covers(pii p, int x){
    int lo, hi;
    lo = p.f;
    hi = p.s;
    if(lo > hi){
        return true;
    }
    return x<=lo && x+k-1 >= hi;
}

bool blank(pii p){
    return p.f > p.s;
}

int main(){
    //file_io();
    cin >> n >> k;
    vector<vector<bool> > arr(n, vector<bool>(n));
    vpi col(n, make_pair(n,-1)), row(n, make_pair(n,-1));
    forn(i,n){
        forn(j,n){
            char c;
            cin >> c;
            arr[i][j] = (c=='B');
            if(arr[i][j]){
                col[j].f = min(col[j].f, i);
                col[j].s = max(col[j].s, i);
                row[i].f = min(row[i].f, j);
                row[i].s = max(row[i].s, j);
            }
        }
    }



    vector<vi> vlines(n,vi(n));
    forn(i,n){
        int cnt = 0;
        forn(x,k){
            if(covers(col[x],i)){
                cnt ++;
            }
        }
        for(int x=k; x < n; x++){
            if(blank(col[x])){
                cnt++;
            }
        }
        vlines[i][0] = cnt;
        for(int j=1; j<n-k+1; j++){
            if(!blank(col[j-1]) && covers(col[j-1],i)){
                cnt--;
            }
            if(!blank(col[j+k-1]) && covers(col[j+k-1],i)){
                cnt++;
            }
            vlines[i][j] = cnt;
        }
    }

    vector<vi> hlines(n,vi(n));
    forn(j,n){
        int cnt = 0;
        forn(x,k){
            if(covers(row[x],j)){
                cnt ++;
            }
        }
        for(int x=k; x < n; x++){
            if(blank(row[x])){
                cnt++;
            }
        }
        hlines[0][j] = cnt;
        for(int i=1; i<n-k+1; i++){
            if(!blank(row[i-1]) && covers(row[i-1],j)){
                cnt--;
            }
            if(!blank(row[i+k-1]) && covers(row[i+k-1],j)){
                cnt++;
            }
            hlines[i][j] = cnt;
        }
    }

    int m = 0;
    forn(i,n-k+1){
        forn(j,n-k+1){
            m = max(m, hlines[i][j] + vlines[i][j]);
        }
    }
    cout << m << endl;
    /*
    forn(i,n){
        cout << col[i] << endl;
    }
    forn(i,n){
        cout << row[i] << endl;
    }
    forn(i,n){
        forn(j,n){
            cout << vlines[i][j];
        }
        cout << endl;
    }
    cout << endl;
    forn(i,n){
        forn(j,n){
            cout << hlines[i][j];
        }
        cout << endl;
    }
    cout << endl;*/
}