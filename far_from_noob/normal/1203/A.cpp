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
        ll a[n];
        fo(i,n)cin>>a[i];
        //cout<<n<<endl;
        if(n<=2){cout<<"YES"<<endl;continue;}
        ll temp;
        fo(i,n)if(a[i]==1)temp=i;
        ll flag=0;
        ll i=temp;
        if(a[(i+1+n)%n]-a[i] == 1){
            ll f=0;
            fo(j,n-1){
                if(a[(j+temp+1+n)%n]-a[(j+temp+n)%n] ==1);
                else {
                    f=1;
                    break;
                }
            }
            if(f==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        else if(a[(i-1+n)%n]-a[i] == 1){
            ll f=0;
            for(int j=0;j<n-1;j++){
                if(a[(-j+temp-1+n+n)%n]-a[(-j+temp+n+n)%n] ==1);
                else {
                    f=1;
                    //cout<<j<<endl;
                    break;
                }
            }
            if(f==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
            
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}