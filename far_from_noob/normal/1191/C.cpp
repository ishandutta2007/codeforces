#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(ll i=0;i<n;i++)
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
            cin>>n;
            cin>>m;
            cin>>k;
            ll a[m];
            fo(i,m)cin>>a[i];
            ll temp=k;
            ll countans=0,used=0;
            if(a[0]<=k)countans++;
            fo(i,m){
                if(a[i]<=temp){
                    used++;
                }
                else {
                    if(a[i]<= temp+used){
                        countans++;
                        temp+=used;
                        used=1;
                    }

                    else {
                        countans++;
                        ll kk=(a[i]-1-temp-used)/k;

                        temp+=k*(kk+1)+used;
                        used=1;
                    }
                }
            } cout<<countans;
    }

    return 0;
}