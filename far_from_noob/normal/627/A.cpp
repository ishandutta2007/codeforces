#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        ll n1=n,m1=m;
        ll a[50],b[50];
        ll count=0;
        for(ll i=45;i>=0;i--){
           a[i]= n/(ll)pow(2,i);
           n=n- n/(ll)pow(2,i) * (ll)pow(2,i);
           b[i]= m/(ll)pow(2,i);
           m=m- m/(ll)pow(2,i) * (ll)pow(2,i);
           if(b[i]==1)count++;
        }
        ll temp=0;
        for(int i=45;i>=0;i--){
            ll x=temp*2+ a[i];
            ll y=b[i];
            if((x==3&&y==1)||(x==0&& y==1)){cout<<0;return 0;}
            if((x==2&&y==0)||(x==1&&y==1)||(x==0&&y==0))temp=0;
            if((x==2&&y==1)||(x==1&&y==0)||(x==0&&y==1)||(x==3&&y==0))temp=1;
            
        }
        if(temp==1)cout<<0;
        else if(n1!=m1)cout<<(ll)pow(2,count);
        else cout<<(ll)pow(2,count) -2;
        
    }

    return 0;
}