#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>t;
    
    while(t--){
        cin>>n;
        int p[n];
        fo(i,n)cin>>p[i];
        sort(p,p+n);
        ll a=p[n-1],b=0,c=0;
        int i=n-2;
        for(i;i>=0;i--){
            if(a%p[i]!=0){b=p[i];break;}
        }
        for( i=i-1;i>=0;i--){
            if(a%p[i]!=0 && b%p[i]!=0){c=p[i];break;}
        }
        ll ans=a+b+c;
        //cout<<ans<<endl;
        for(i=n-2;i>=0;i--){
            if(p[i]!=p[n-1]){a=p[i];break;}
        }
        i=i-1;
         b=0,c=0;
        
        for(i;i>=0;i--){
            if(a%p[i]!=0){b=p[i];break;}
        }
        for( i=i-1;i>=0;i--){
            if(a%p[i]!=0 && b%p[i]!=0){c=p[i];break;}
        }
        if(a+b+c>ans)cout<<a+b+c<<endl;
        else cout<<ans<<endl;
        
            
    }

    return 0;
}