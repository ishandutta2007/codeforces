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
    vi v;
    int mi;
    forn(i,n){
        int x;
        cin >> x;
        if(x==n){
            mi = i;
        }
        v.pb(x);
    }
    int left = mi;
    int right = mi;
    bool works = true;
    for(int i=n-1; i>0; i--){
        //cout << mi << left << right << endl;
        if(left>0 && v[left-1]==i){
            left--;
        }else if(right<n-1 && v[right+1]==i){
            right++;
        }else{
            works = false;
        }
    }
    if(works){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}