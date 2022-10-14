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
    int n, m, k;
    cin >> n >> m >> k;
    vi v(n);
    forn(i,n){
        int x;
        cin >> x;
        v[i] = x;
    }
    lint best = 0;
    forn(start,m){
        lint curr = 0;
        int i=start;
        while(i<n){
            if((i-start)%m == 0){   //new block
                if(curr<0){
                    curr = 0;
                }
                curr -= k;
            }
            curr += v[i];
            best = max(curr,best);
            //cout << start << " " << i << " " << curr << " " << best << endl;
            i++;
        }
    }
    cout << best << endl;
}