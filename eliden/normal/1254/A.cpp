#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int n, m, k;
        cin >>n>>m>>k;
        vector<string> input(n);
        rep(i,0,n) cin >> input[i];
        int rice=0;
        rep(i,0,n) rep(j,0,m) if(input[i][j]=='R') ++rice;
        int div=rice/k, mod=rice%k;
        int ind=0, current=0;
        vector<vi> ans(n,vi(m));
        rep(i,0,n) rep(jj,0,m) {
            int j = jj;
            if(i%2==1) j = m-1-jj;
            int target = div;
            if(ind<mod) ++target;
            if(input[i][j]=='R') ++current;
            if(current>target) {
                current = 1;
                ++ind;
            }
            ans[i][j] = ind;
        }
        rep(i,0,n) {
            rep(j,0,m) {
                int x = ans[i][j];
                if(x<10) cout<<(char)('0'+x);
                else if(x<36) cout<<(char)('A'+x-10);
                else cout<<(char)('a'+x-36);
            }
            cout<<"\n";
        }
    }

}