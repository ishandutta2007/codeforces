#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
vector<ll>v[100005];
ll ans[100005];
map<pair<ll,ll > ,ll >m1;
ll val;
void dfs(ll node,ll root){
    if(v[node].size()==1&& node!=root){ans[node]=0; return ;}
    fo(i,v[node].size()){
        if(v[node][i]!=root)dfs(v[node][i],node);
    }
    ans[node]=0;
    fo(i,v[node].size()){
        if(v[node][i]!=root)ans[node]+=(ans[v[node][i]]+m1[mp(node,v[node][i])]);
    }
}
ll maxi=0;
void dfs2(ll node,ll root, ll val){
    if(v[node].size()==1&& node!=root){maxi=max(maxi,val); return ;}
    fo(i,v[node].size()){
        if(v[node][i]!=root)dfs2(v[node][i],node,val+m1[mp(node,v[node][i])]);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        
        fo(i,n-1){
            ll a,b,c;
            cin>>a>>b>>c;
            v[a].pb(b);
            v[b].pb(a);
            m1[mp(a,b)]=c;
            m1[mp(b,a)]=c;
        }
        dfs(1,1);
        val=0;
        dfs2(1,1,val);
        
        cout<<2*ans[1]-maxi;
    }

    return 0;
}