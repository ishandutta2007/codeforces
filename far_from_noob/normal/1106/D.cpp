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
vector<ll>v[100005];
ll ifused[100005];
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
priority_queue<ll>pq;
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        cin>>n>>m;
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        fo(i,n+1)ifused[i]=0;
        
        pq.push(1);
        //cout<<1<< " ";
        ifused[1]=1;
        while(pq.size()){
                ll b=pq.top();
                
                cout<<b<< " ";
                pq.pop();
                fo(i,v[b].size()){
                    if(ifused[v[b][i]]==0){
                        //cout<<v[b][i]<<  " ";
                        
                        pq.push(v[b][i]);
                        ifused[v[b][i]]=1;
                    }
                }
                
        }
        
    
    }

    return 0;
}