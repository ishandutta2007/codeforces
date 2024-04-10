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
        
        map<ll,ll>m1;
        ll temp=1;
        cin>>n;
        vector<pair<ll,pair<ll,ll> >>v[n+1];
        pair<pair<ll,ll>,pair<ll,ll>>p[n];
        pair<pair<ll,ll>,pair<ll,ll>>p1[n];
        pair<pair<ll,ll>,pair<ll,ll>>p2[n];
        ll n1=0;
        ll n2=0;
        ll x[n],y[n],z[n];
        fo(i,n){cin>>x[i]>>y[i]>>z[i];
            if(m1[x[i]]==0)m1[x[i]]=temp,temp++;
            p[i]=mp(mp(x[i],y[i]),mp(z[i],i));
        }
        sort(p,p+n);
        fo(i,n){
            if(i==n-1){p1[n1]=p[i],n1++;break;}
            if(p[i].fi.fi==p[i+1].fi.fi && p[i].fi.se==p[i+1].fi.se){
            cout<<p[i].se.se +1<<" "<<p[i+1].se.se+1<<endl;
            i++;
            }
            else p1[n1]=p[i],n1++;
        }
        fo(i,n1){
            if(i==n1-1){p2[n2]=p1[i],n2++;break;}
            if(p1[i].fi.fi==p1[i+1].fi.fi ){
            cout<<p1[i].se.se+1 <<" "<<p1[i+1].se.se+1<<endl;
            i++;
            }
            else p2[n2]=p1[i],n2++;
        }
        fo(i,n2){
            cout<<p2[i].se.se+1<<" "<<p2[i+1].se.se+1<<endl;
            i++;
        }
        
        
        
    }

    return 0;
}