#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,x,flag=0;
vector<ll>v[1000000];
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
    ll p;
    cin>>n>>p;
    string s[n];
    fo(i,n)cin>>s[i];
    ll mt=0;
    ll temp=0;
    for(int i=n-1;i>=0;i--){
        if(s[i].size()==8){
            temp=temp*2+1;
            mt+=temp  * p/2;
        }

        else {
            temp*=2;
            mt+=temp/2 * p;
        }
        //cout<<mt<<" ";
    }
    cout<< mt;



    return 0;
}