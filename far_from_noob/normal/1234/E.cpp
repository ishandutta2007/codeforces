#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        ll a[m];
        fo(i,m)cin>>a[i];
        ll sum=0;
        fo(i,m-1){
            sum+=abs(a[i+1]-a[i]);
        }
        ll p[n+2],q[n+2];
        fo(i,n+2)p[i]=0,q[i]=0;
        fo(i,m-1){
            if(a[i]==a[i+1]);
            else{
                ll a1=min(a[i],a[i+1]),b=max(a[i],a[i+1]);
                p[a1+1]++;
                p[b]--;
                q[a1]+=a1-1;
                q[b]-=(b-a1);
                q[b]+=a1;
            }
        }
        fo1(i,n+1)p[i]=p[i]+p[i-1];
        fo1(i,n)cout<<sum-p[i]+q[i]<<" ";
        
        
        
        
    }

    return 0;
}