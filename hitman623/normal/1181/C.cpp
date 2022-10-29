#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define right       lkjlkj
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,down[1001][1001],right[1001][1001],rmd[1001][1001],rmu[1001][1001],ans;
string s[1001];
void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        right[i][m-1]=m-1;
        for(int j=m-2;j>=0;j--){
            if(s[i][j]==s[i][j+1]) right[i][j]=right[i][j+1];
            else right[i][j]=j;
        }
    }
    rep(j,0,m){
        down[n-1][j]=n-1;
        for(int i=n-2;i>=0;i--){
            if(s[i][j]==s[i+1][j]) down[i][j]=down[i+1][j];
            else down[i][j]=i;
        }
    }
    rep(j,0,m){
        rmd[n-1][j]=right[n-1][j];
        for(int i=n-2;i>=0;i--){
            if(s[i][j]==s[i+1][j]) rmd[i][j]=min(right[i][j],rmd[i+1][j]);
            else rmd[i][j]=right[i][j];
        }
    }
    rep(j,0,m){
        rmu[0][j]=right[0][j];
        rep(i,1,n){
            if(s[i][j]==s[i-1][j]) rmu[i][j]=min(right[i][j],rmu[i-1][j]);
            else rmu[i][j]=right[i][j];
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            int len=down[i][j]-i+1;
            if(i+len<n and down[i+len][j]==i+2*len-1 and i+2*len<n and down[i+2*len][j]>=i+3*len-1 and s[i+len][j]!=s[i][j] and s[i+2*len][j]!=s[i+len][j]){
                ans+=min({rmd[i][j],rmd[i+len][j],rmu[i+3*len-1][j]})-j+1;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}