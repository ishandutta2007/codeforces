#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> val(k,2);
        bool bad = false;
        rep(i,0,n) if(s[i]!='?') {
            int x = s[i]-'0';
            if(val[i%k]==2) val[i%k] = x;
            else if(val[i%k]!=x) bad = true;
        }
        int zs=0, os=0;
        rep(i,0,k) {
            if(val[i]==0) ++zs;
            if(val[i]==1) ++os;
        }
        if(zs>k/2 || os>k/2) bad = true;
        if(bad) cout<<"NO\n";
        else cout<<"YES\n";
    }
}