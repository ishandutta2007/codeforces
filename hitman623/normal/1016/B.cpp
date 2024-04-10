#include <bits/stdc++.h>

#define ll          long long
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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,q,dp[1001][1001],isgood[1001];
string s,t;
void solve(){
    cin>>n>>m>>q;
    cin>>s>>t;
    rep(i,0,n){
        int f=1;
        rep(j,0,m){
            if(i+j>=n || s[i+j]!=t[j]){f=0;break;}
        }
        if(f) isgood[i]=1;
    }
    rep(i,1,n+1){
        rep(j,0,n){
            if(j+i-1>=n) break;
            if(i==1) dp[j][j+i-1]=((j+i-1>=j+m-1)?isgood[j]:0);
            else dp[j][j+i-1]=dp[j+1][j+i-1]+((j+i-1>=j+m-1)?isgood[j]:0);
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<dp[l][r]<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}