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
        ll d;
        cin>>n>>k>>d;
        ll a[n];
        fo(i,n)cin>>a[i];
        sort(a,a+n);
        map<ll,ll>minindex; 
        ll dp[n+1];
        fo(i,n){
            if(minindex[a[i]]==0)minindex[a[i]]=i+1;
        }       
        dp[0]=1;
        fo(i,n)dp[i+1]=0;
        ll count[n+1];
        count[0]=1;
        multiset<ll>s;
        fo(i,n)s.insert(a[i]);
        multiset<ll>:: iterator it;
        fo(i,n){
            ll kk;
            it=s.lower_bound(a[i]-d);
            kk=*it;
            //cout<<kk;
            ll index=minindex[kk]-1;
            //cout<<i+1-k<<" "<<index<<endl;
            if(i-k+1>=index){
                if(index==0){
                    if(count[i-k+1]>0)count[i+1]=count[i]+1;
                    else count[i+1]=count[i];
                }
                else{
                    if(count[i-k+1]- count[index-1]>0)count[i+1]=count[i]+1;
                    else count[i+1]=count[i];
                }
            }
            else count[i+1]=count[i];
            //cout<<count[i+1]<<endl;
        }
        if(count[n]==count[n-1])cout<<"NO";
        else cout<<"YES";
    }

    return 0;
}