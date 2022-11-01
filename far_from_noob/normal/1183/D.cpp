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
map<int,int>pcount;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    ll a ,b;
    while(t--){
        cin>>n;
        int a[n+1];
        fo(i,n+1)a[i]=0;
        fo(i,n)cin>>k,a[k]++;
        sort(a,a+n+1);
        ll ans=0,temp=n+5;
        for(int i=n;i>0;i--){
            if(a[i]<temp)ans+=a[i],temp=a[i];
            else ans+=temp-1,temp--;
            if(temp==0)break;
        }
        cout<<ans<<endl;

    }





    return 0;
}