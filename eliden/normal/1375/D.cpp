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
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n;
        cin>>n;
        vector<int> a(n);
        rep(i,0,n) cin>>a[i];
        vector<int> ans;
        while(true) {
            vector<bool> seen(n+1);
            rep(i,0,n) seen[a[i]] = true;
            int mex=0;
            while(seen[mex]) ++mex;
            if(mex<n) {
                a[mex] = mex;
                ans.push_back(mex);
            }
            else {
                int j = 0;
                while(j<n && a[j]==j) ++j;
                if(j==n) break;
                a[j] = mex;
                ans.push_back(j);
            }
        }
        cout<<sz(ans)<<"\n";
        for(int x:ans) cout<<x+1<<" ";
        cout<<"\n";
    }
}