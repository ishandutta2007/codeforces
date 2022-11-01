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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
        ll x0,y0,ax,bx,ay,by,xs,ys,t;
        cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
        vector<pair<ll,ll> >p;
        while(x0<100000000000000000 && y0<100000000000000000){
            //cout<<x0<<endl;
            p.pb(mp(x0,y0));
            if(x0>10000000000000000|| y0>10000000000000000)break;
            x0=ax*x0+  bx;
            y0=ay*y0+by;
            
        }
        //cout<<p.size();
        ll ans=0;
        ll l=p.size();
        for(int i=0;i<l;i++){
            ll temp=t;
            ll tans=0;
            ll j=i;
            ll xx=xs,yy=ys;
            while(temp>0 && j>=0 ){
                temp-=abs(xx-p[j].fi)+abs(yy-p[j].se);
                xx=p[j].fi;
                yy=p[j].se;
                if(temp>=0)tans++;
                j--;
            }
            ans=max(ans,tans);
        }
        for(int i=0;i<l;i++){
            ll temp=t;
            ll tans=0;
            ll j=0;
            ll xx=xs,yy=ys;
            while(temp>0 && j<l ){
                temp-=abs(xx-p[j].fi)+abs(yy-p[j].se);
                xx=p[j].fi;
                yy=p[j].se;
                if(temp>=0)tans++;
                j++;
            }
            ans=max(ans,tans);
        }
 
        cout<<ans;
 
        
    }
 
    return 0;
}