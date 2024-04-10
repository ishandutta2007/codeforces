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
int n,odd[200005],even[200005],s[200005],sum,oddsum;
vi a[200005];
void dfs(int node,int par){
    s[node]=1;
    even[node]=1;
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node);
            s[node]+=s[i];
            odd[node]+=even[i];
            even[node]+=odd[i];
            sum+=s[i]*(n-s[i]);
        }
    }
}
void dfs2(int node,int par){
    oddsum+=odd[node];
    for(auto i:a[node]){
        if(i!=par){
            odd[node]-=even[i];
            even[node]-=odd[i];
            odd[i]+=even[node];
            even[i]+=odd[node];
            dfs2(i,node);
            odd[i]-=even[node];
            even[i]-=odd[node];
            odd[node]+=even[i];
            even[node]+=odd[i];
        }
    }
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<(sum+oddsum/2)/2<<endl;
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