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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,x[200005],ans,pos;
unordered_map<int,int> mp;
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>x[i];
        if(x[i]==m) x[i]=0,pos=i;
        else if(x[i]<m) x[i]=-1;
        else x[i]=1;
        x[i]=x[i]+x[i-1];
    }
    rep(i,pos,n+1){
        mp[x[i]]++;
    }
    rep(i,0,pos){
        ans+=mp[x[i]]+mp[x[i]+1];
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