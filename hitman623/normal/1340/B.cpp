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
string s[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int cnt[1<<7][10];
int mask[10];
int n,a[2002],res[2002],dp[2002][2002];
int go(int x,int k){
    if(x==n) return k==0;
    int &ans=dp[x][k];
    if(ans!=-1) return ans;
    for(int i=9;i>=0;i--){
        if(cnt[a[x]][i]<=k and go(x+1,k-cnt[a[x]][i])){
            res[x]=i;
            return ans=1;
        }
    }
    return ans=0;
}
void solve(){
    memset(dp,-1,sizeof dp);
    rep(i,0,10){
        rep(j,0,7){
            mask[i]=mask[i]*2+s[i][j]-'0';
        }
    }
    rep(i,0,1<<7){
        rep(j,0,10){
            if((i&mask[j])==i){
                cnt[i][j]=__builtin_popcount(i^mask[j]);
            }
            else cnt[i][j]=hell;
        }
    }
    int k;
    cin>>n>>k;
    rep(i,0,n){
        string w;
        cin>>w;
        rep(j,0,7){
            a[i]=a[i]*2+w[j]-'0';
        }
    }
    if(go(0,k)){
        rep(i,0,n) cout<<res[i];
        cout<<endl;
    }
    else cout<<-1<<endl;
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