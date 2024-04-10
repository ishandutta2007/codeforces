#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=998244353;
ll n,k,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll li(ll a,ll  b){
    if(a%b==0)return a/b;
    else return a/b +1;
    
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m>>k;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll ans=0;
        ll p[m][n];
        for(int j=0;j<m;j++){
            ll temp=0,index=j;
            ll pack=0;
            for( index;index<n;index++){
                if((index+1-j)%m==0){
                    temp+=a[index];
                    ans=max(ans,temp-k);
                    temp=temp-k;
                    if(temp>0);
                    else temp=0;
                }
                else {
                    //pack+=a[index];
                    temp+= a[index];
                    ans=max(ans,temp-k);
                }
                
            }
        }
        
        
        cout<<ans;
        
    }

    return 0;
}