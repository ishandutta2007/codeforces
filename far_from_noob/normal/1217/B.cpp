
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    //t=1;
    
    while(t--){
        flag=0;
        cin>>n;
        ll x;
        cin>>x;
        ll a[n],h[n];
        fo(i,n){
            cin>>a[i]>>h[i];
        }
        ll c[n],temp=0;
        fo(i,n){
            if(x<=a[i] && flag==0){
                cout<<1<<endl;
                flag=1;
            }
            else c[temp]=(a[i]-h[i]),temp++;
            
        }
        if(flag==0){
            
            sort(a,a+n);
            x=x-a[n-1];
            sort(c,c+temp);
            if(c[temp-1]<=0){cout<<-1<<endl;continue;}
            ll b;
            if(x%c[temp-1]==0)cout<<x/c[temp-1]+1;
            else cout<<x/c[temp-1]+2;
            cout<<endl;
        }
        
        
    }
 
    return 0;
}