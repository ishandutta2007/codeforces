#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
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
ll md[100+1][100+1];
vector<ll>v[100+1];
ll bfs(ll i,ll j,queue<ll>q,ll z,map<ll,ll>m1){
    
    ll o=q.size();
    if(o==0)return -1;
    fo(l,o){
    ll b=q.front();
    if(b==j)return z;
    else {
        
        if(m1[b]!=1)fo(i,v[b].size()){
            q.push(v[b][i]);
        }
        m1[b]=1;
        q.pop();
    }
    }
    return bfs(i,j,q,z+1,m1);
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        char c[n][n];
        fo(i,n)fo(j,n)cin>>c[i][j];
        
        fo(i,n){
            fo(j,n){
                //cin>>k;
                if(c[i][j]=='1')
                v[i+1].pb(j+1);
                //cout<<i<<j<<endl;}
            }
        }
        
        fo(i,n){
            fo(j,n){
                queue<ll>q;
                map<ll,ll>m1;
                q.push(i+1);
                md[i+1][j+1]=bfs(i+1,j+1,q,0,m1);
                //cout<<md[i+1][j+1];
            }
            
        }
        
        ll m;
        cin>>m;
        ll a[m];
        fo(i,m)cin>>a[i];
        vector<ll>ans;
        ll pi=a[0],pii=0;
        ans.pb(a[0]);
        for(int i=1;i<m;i++){
            if(md[pi][a[i]]==i-pii);
            else {
                ans.pb(a[i-1]);
                pi=a[i-1];
                pii=i-1;
            }
        }
        cout<<ans.size()+1;
        cout<<endl;
        fo(i,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<a[m-1];
        
    }

    return 0;
}