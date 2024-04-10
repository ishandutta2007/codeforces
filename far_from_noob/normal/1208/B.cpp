#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=998244353;
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
//ll fac[1000000];

int main() {
    
    //cout<<fac[31]<<endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll ans;
        map<ll,ll>m1;
        map<ll,ll>m2;
        map<ll,ll>m3;
        
        ll temp=-1;
        for(int i=n-1;i>=0;i--){
            m2[a[i]]++;
            if(m2[a[i]]==2){m2[a[i]]--;temp=i;break;}
        }
        ans=temp+1;
        //cout<<ans<<endl;
        fo(i,n){
            m3[a[i]]++;
            if(m3[a[i]]==2){ans=min(ans,n-i);break;}
        }
        fo(i,n){
            m1[a[i]]++;
            if(m1[a[i]]==2)break;
            temp=max(temp,i);
            if(temp==n-1){ans=min(ans,temp-i);break;}
            for(int j=temp+1;j<n;j++)if(m2[a[i]]==1){m2[a[j]]--;temp++;}else break;
            ans=min(ans,temp-i);
            
            
        }
        cout<<ans;
        
        
        
    }

    return 0;
}