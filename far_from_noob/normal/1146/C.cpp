#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
//#define endl "\n"
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
    //t=1;
    while(t--){
        
        cin>>n;
        ll temp=1,max=0;
        while(temp < n){
            ll ok=0;
            ll i=0;
            while(i<n){
                if((i/temp)%2 == 0 )ok++;
                i++;
            }
            cout<<ok<< " "<< n-ok<< " ";
            i=0;
            while(i<n){
                if((i/temp)%2 == 0 )cout<< i+1<<" ";
                i++;
            }
            i=0;
            while(i<n){
                if((i/temp)%2 == 0 );
                else cout<<i+1<<" ";
                i++;
            }
            cout<<endl;
            cout.flush();
            cin>>k;
            if(k>max)max=k;
            temp*=2;
            
            
            
        }
        cout<<"-1 "<<max<<endl;
        
    }

    return 0;
}