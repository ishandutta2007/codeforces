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
    //cin>>t;
    t=1;
    while(t--){
            cin>>n;
    cin>>k;

    if(k>n*n ){cout<<-1;return 0;}
    int a[n][n];
    fo(i,n)fo(j,n)a[i][j]=0;
    if(k>0){
    int p=(int)sqrt(n*n-k);
     k -= n*n - (p+1)*(p+1);
     p=n-p;
     //cout<<p<<k<<endl;;
    fo(i,n)fo(j,n){if(i<p-1||j<p-1)a[i][j]=1;  }
    if(k>0){a[p-1][p-1]=1;
    k=k-1;
    for(int i=0;i<k/2;i++){
            //cout<<" ";
        a[p-1][p+i]=1;
        a[p+i][p-1]=1;
    }
    if(k%2==1)a[p][p]=1;}
    }

    fo(i,n){
    fo(j,n)cout<<a[i][j]<<" ";
    cout<<endl;
    }






    }

    return 0;
}