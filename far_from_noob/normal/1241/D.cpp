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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n ;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll amin[n+1],amax[n+1];
        fo(i,n+1)amin[i]=n+1,amax[i]=0;
        fo(i,n){
            amin[a[i]]=min(amin[a[i]], i+1);
            amax[a[i]]=max(amax[a[i]], i+1);
        }
        ll mini=0,maxi=0;
        ll temp=-1;
        ll ans=0;
        ll count=0;
        //fo(i,n+1) cout<<amin[i]<<" "<<amax[i]<<" ";
        fo(i,n+1){
            if(amax[i]!=0){
                count++;
                if(amin[i]> maxi){
                    temp++;
                    ans=max(ans,temp);
                }
                else {
                    temp=0;
                }
                
                
                mini=amin[i];
                maxi=amax[i];
            }
        }
        cout<<count-1-ans<<endl;
    }

    return 0;
}