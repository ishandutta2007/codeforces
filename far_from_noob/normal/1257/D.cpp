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
        cin>>n;
        ll a[n];
        ll ma[n+1];
        fo(i,n+1)ma[i]=0;
        fo(i,n)cin>>a[i];
        cin>>m;
        fo(i,m){
            ll c,b;
            cin>>c>>b;
            ma[b]=max(c,ma[b]);
        }
        vector<pair<ll,ll>>vp;
        fo(i,n+1){
            if(ma[i]>0)vp.pb(mp(i,ma[i]));
        }
        ll l=vp.size();
        //fo(i,l)cout<<vp[i].fi<<vp[i].se;
        ll maxi[l];
        fo(i,l)maxi[i]=0;
        maxi[l-1]=vp[l-1].se;
        for(int i=l-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],vp[i].se);
        }
        //fo(i,l)cout<<vp[i].fi<<maxi[i]<<endl;
        ll ans=0;
        ll temp=0;
        ll temp2=0;
        ll tempmax=0;
        ll count=0;
        ll flag=0;
        while(temp<n){
            tempmax=max(tempmax,a[temp]);
            if(tempmax>maxi[0]){flag=1; break;}
            count++;
            if(count>vp[temp2].fi)temp2++;
            if(temp2==l){
                ans++;
                tempmax=0;
                count=0;
                temp2=0;
                continue;
            }
            if(tempmax<=maxi[temp2])temp++;
            else {
                ans++;
                tempmax=0;
                count=0;
                temp2=0;
            }
        }
        if(flag==1)cout<<-1<<endl;
        else cout<<ans+1<<endl;
    }
    return 0;
}