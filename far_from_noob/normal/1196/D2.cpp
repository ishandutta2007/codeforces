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
    //t=1;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        ll l=s.size();
        ll c[3];
        ll lmin=l;
        ll temp=0;
        ll a[l];
        c[0]='R',c[1]='G',c[2]='B';
        for(int i=0;i<l;i++){
            if(s[i]==c[i%3])a[i]=0;
            else a[i]=1;
            
        }
        fo(i,k)temp+=a[i];
        lmin=min(temp,lmin);
        //cout<<lmin<<endl;
        for(int i=k;i<l;i++){
            temp+=a[i]-a[i-k];
            lmin=min(temp,lmin);
        }
        if(1){
            temp=0;
            for(int i=0;i<l;i++){
            if(s[i]==c[(i+2)%3])a[i]=0;
            else a[i]=1;
        }
        fo(i,k)temp+=a[i];
        lmin=min(temp,lmin);
        //cout<<lmin<<endl;
        for(int i=k;i<l;i++){
            temp+=a[i]-a[i-k];
            lmin=min(temp,lmin);
        }
        }
        if(1){
            temp=0;
            for(int i=0;i<l;i++){
            //cout<<c[(i+ 1)%3]<<" ";
            if(s[i]==c[(i+1)%3])a[i]=0;
            else a[i]=1;
            //out<<a[i]<<" ";
        }
        //cout<<endl;
        fo(i,k)temp+=a[i];
        //cout<<temp<<endl;
        lmin=min(temp,lmin);
        //cout<<lmin<<endl;
        for(int i=k;i<l;i++){
            temp+=a[i]-a[i-k];
            //cout<<temp<<endl;
            lmin=min(temp,lmin);
        }
        }
            
        cout<< lmin<<endl;
        
    }

    return 0;
}