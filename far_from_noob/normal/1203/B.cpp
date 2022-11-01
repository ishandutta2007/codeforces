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
        cin>>n;
        ll a[n*4];
        fo(i,4*n)cin>>a[i];
        sort(a,a+4*n);
        ll temp=a[0]*a[4*n-1];
        flag=0;
        fo(i,n){
            if(a[2*i]*a[4*n -1 -2*i] == temp && a[2*i]==a[2*i +1] && a[4*n -1 -2*i]==a[4*n -1 -2*i -1]);
            else flag=1;
        }
        if(flag==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

    return 0;
}