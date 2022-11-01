#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
vector<int>v[200005];queue<int>s;
ll n,k,t,m,p,q,x,flag=0,ans=0,waiting=0;
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
        cin>>n>>k;
        ll a[n];
        ll flag=0;
        fo(i,n)cin>>a[i];
        sort(a,a+n);
        if(a[n-1]-a[0] <= 2*k)cout<<a[0]+k<<endl;

        else cout<<-1<<endl;



    }





    return 0;
}