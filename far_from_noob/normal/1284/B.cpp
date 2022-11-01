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
        cin>>n;
        ll mini[n],maxi[n];
        vector<ll>maxii,minii;
        fo(i,n){
            mini[i]=mod,maxi[i]=0;
            ll l;
            cin>>l;
            ll flag=0;
            fo(j,l){
                cin>>k;
                mini[i]=min(mini[i],k);
                maxi[i]=max(maxi[i],k);
                if(k>mini[i])flag=1;
            }
            if(flag==0)maxii.pb(maxi[i]),minii.pb(mini[i]);

        }
        ll l=minii.size();
        //cout<<l;
        sort(all(minii));
        sort(all(maxii));
        ll ans=0;
        ll temp=0;
        fo(i,l){
            if(maxii[temp]>minii[i])ans+=l-temp;
            else{
                temp++;
                i--;
            }
            if(temp==l)break;
        }
        cout<<ans+ n*n-l*l<<endl;
    }

    return 0;
}