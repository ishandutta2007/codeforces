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
    string s;
    cin>>s;
    int q;
    cin>>q;
    int n = sz(s);
    vector<vector<int>> sum(26,vector<int>(n+1));
    rep(i,0,26) {
        rep(j,1,n+1) {
            sum[i][j] = sum[i][j-1];
            if(s[j-1]-'a'==i) ++sum[i][j];
        }
    }
    rep(i,0,q) {
        int l, r;
        cin>>l>>r;
        int count = 0;
        rep(j,0,26) if(sum[j][r]-sum[j][l-1]>0) ++count;
        if(l==r || count>=3 || s[l-1]!=s[r-1]) cout<<"Yes\n";
        else cout<<"No\n";
    }
}