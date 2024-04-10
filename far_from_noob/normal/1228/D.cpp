#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fo(i,n) for(int i=0;i<n;i++)
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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        pair<ll,ll>p[m];
        vector<ll>v[n+1];
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
            p[i]=mp(a,b);
        }
        map<ll,ll>m1;
        ll temp=0;
        m1[1]=1;
        ll v1,v2=0,v3=0;
        v1=n-v[1].size();
        for(int i=2;i<=n;i++){
            m1[i]=1;
        }
        fo(i,v[1].size()){
            m1[v[1][i]]=0;
        }
        if(v[1].size()==0){cout<<-1;return 0;}
        m1[v[1][0]]=2;
        
        for(int i=1;i<=n;i++){
            if(m1[i]==0)m1[i]=2;
        }
        v2=n-v[v[1][0]].size();
        v3=n-v1-v2;
        if(v1==0||v2==0||v3==0){cout<<-1;return 0;}
        //cout<<v1<<v2<<v3;
        fo(i,v[v[1][0]].size()){
            if(m1[v[v[1][0]][i] ]!=1)m1[v[v[1][0]][i] ]=3;
        }
        for(int i=1;i<=n;i++){
            if(m1[i]==1 && n-v[i].size()!= v1){cout<<-1;return 0;}
            if(m1[i]==2 && n-v[i].size()!= v2){cout<<-1;return 0;}
            if(m1[i]==3 && n-v[i].size()!= v3){cout<<-1;return 0;}
        }
        fo(i,m){
            if(m1[p[i].first] == m1[p[i].second]){cout<<-1;return 0;}
        }
        for(int i=1;i<=n;i++)cout<<m1[i]<< " ";
            
        
        
    }

    return 0;
}