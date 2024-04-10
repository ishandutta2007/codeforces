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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    //t=1;
    while(t--){
        cin>>n>>k;
        ll a[n];
        fo(i,n)
        cin>>a[i];  
        ll temp=0;
        ll tempsum=0;
        vector<int >v;
        fo(i,n){
            if(a[i]%2==1)temp++,v.push_back(i);
        }
        if(temp<k|| (temp-k)%2==1)cout<<"NO"<<endl;
        else {cout<<"YES"<<endl;fo(i,k-1)cout<<v[i]+1<<" ";cout<<n<<endl;}
    }

    return 0;
}