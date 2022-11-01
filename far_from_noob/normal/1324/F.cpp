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
vector<ll>v[300000];
ll color[200005];
ll ans[200005];
void ans1(ll node, ll root ){
    fo(i,v[node].size()){
        if(v[node][i]!=root)ans1(v[node][i],node);
    }
    ll tsum=0;
    fo(i,v[node].size()){
        if(v[node][i]!=root)tsum+=max(0,ans[v[node][i]]);
    }
    //if(node==9)cout<<tsum<<endl;
    if(color[node]==1)tsum++;
    else tsum--;
    ans[node]=tsum;

}
void ans2(ll node , ll root){
    fo(i,v[node].size()){
        if(v[node][i]!=root){
            if(ans[v[node][i]]>=0)ans[v[node][i]]=max(ans[v[node][i]] , ans[node]);
            else ans[v[node][i]]=max(ans[v[node][i]],  ans[node]  + ans[v[node][i]]);
            ans2(v[node][i], node);
        }    

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
        //color[n];
        fo(i,n)cin>>color[i+1];
        //vector<ll>v[n];
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        fo1(i,n)ans[i]=-1;
        ans1(1,1);
        //fo(i,n)cout<<ans[i+1]<<" ";cout<<endl;
        ans2(1,1);
        fo(i,n)cout<<ans[i+1]<<" ";



        
    }

    return 0;
}