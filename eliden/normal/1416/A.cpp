#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
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
        vector<vi> inds(n);
        rep(i,0,n) inds[a[i]-1].push_back(i);
        vector<int> ans(n+2,n+1);
        rep(i,0,n) {
            //inds[i].push_back(-1);
            inds[i].push_back(n);
            sort(all(inds[i]));
            int last = -1;
            int most = 0;
            for(int j : inds[i]) {
                most=max(most,j-last-1);
                last = j;
            }
            ans[most+1]=min(ans[most+1],i+1);
        }
        rep(i,1,n+1) {
            ans[i]=min(ans[i],ans[i-1]);
            if(ans[i]==n+1) cout<<-1;
            else cout<<ans[i];
            if(i==n) cout<<"\n";
            else cout<<" ";
        }
    }
}