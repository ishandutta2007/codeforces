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
        cin>>n>>m;
        ll a[m];
        ll sum=0;
        ll mini=mod;
        fo(i,m){cin>>a[i],sum+=a[i]; if ( n- a[i] < i){cout<<-1; return 0;}  }
        pair<ll,ll>p[m];
        fo(i,m){
            p[i]=mp(a[i], i);
        }
        //sort(p,p+m);
        mini=a[m-1];
        if(sum<n || mini + m-1 > n ){cout<<-1; return 0;}

        ll ans[m];
        //cout<<m- p[0].se;
        ans[0]=1;
        ll  temp=1;
        //ll temp= n+1 - p[0].fi;
        ll bache=m-1;
        ll presum=a[0];
        for(int i=1;i<m;i++){
            
            ans[i] = max( temp+1 , n+1-(sum-presum));
            temp= max( temp+1 , n+1-(sum-presum));
            presum+=a[i];
        }
        fo(i,m)cout<<ans[i]<<" ";

        
    }

    return 0;
}