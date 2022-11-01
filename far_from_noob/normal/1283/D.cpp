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
        cin>>n>>m;
        ll a[n];
        map<ll,ll>m1;
        vector<ll>ans;
        queue<pair<ll,ll> >q;
        fo(i,n){
            cin>>a[i];
            m1[a[i]]=1;
            q.push(mp(a[i],0));
        }
        ll mainans=0;
        while(ans.size()<m){
            pair<ll,ll> node=q.front();
            q.pop();
            if(m1[node.fi+1]==0)ans.pb(node.fi+1),m1[node.fi+1]=1,mainans+=node.se+1,q.push(mp(node.fi+1,node.se+1));
            if(m1[node.fi-1]==0&&ans.size()<m)ans.pb(node.fi-1),m1[node.fi-1]=1,mainans+=node.se+1,q.push(mp(node.fi-1,node.se+1));
        }
        cout<<mainans<<endl;
        fo(i,m)cout<<ans[i]<<" ";




        
    }

    return 0;
}