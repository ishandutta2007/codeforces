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
    ll a ,b;
    while(t--){
        cin>>k>>n>>a>>b;
        if(k<=n*b){cout<<-1<<endl;continue;}
        else a=a-b;
        k=k-n*b -1;
        if(k/a>n)cout<<n<<endl;
        else
        cout<<k/a<<endl;


    }





    return 0;
}