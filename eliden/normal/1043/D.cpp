#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(m, vector<int>(n)), inv(m, vector<int>(n));
    rep(i,0,m) {
        rep(j,0,n) {
            int x;
            cin >> x;
            --x;
            p[i][j] = x;
            inv[i][x] = j;
        }
    }
    ll tot=0;
    int j=0;
    while(j<n) {
        ll len=1;
        bool ok = true;
        while(ok) {
            ++len;
            rep(i,0,m) {
                int jj = inv[i][p[0][j]]+len-1;
                if(jj>=n || p[i][jj]!=p[0][j+len-1]) {
                    ok=false;
                    break;
                }
            }
        }
        --len;
        tot += len*(len+1)/2;
        j+=len;
    }
    cout << tot << endl;
}