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
        ll a[n];
        ll sum=0;
        fo(i,n){
            cin>>a[i];
            sum+=a[i];
        }
        ll count[n+1];
        fo1(i,n)count[i]=0;
        ll tempcount=0;
        map<ll,ll>m1[n+1];
        cin>>q;
        fo(j,q){
            ll b,c,k;
            cin>>b>>c>>k;
            if(m1[b][c]==0){
                if(k!=0)
                {
                if(count[k]<a[k-1])tempcount++;
                count[k]++;
                }
                cout<<sum-tempcount<<endl;
                m1[b][c]=k;
            }
            else {
                ll l=m1[b][c];
                if(count[l]<=a[l-1])tempcount--;
                count[l]--;
                if(k!=0){
                if(count[k]<a[k-1])tempcount++;
                count[k]++;
                }
                cout<<sum-tempcount<<endl;
                
                m1[b][c]=k;

            }


        }
        
    }

    return 0;
}