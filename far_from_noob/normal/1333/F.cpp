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
ll val[500005];
ll m1[500004];
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
        ll ans[n+1];
        fo(i,n+1)ans[i]=1;
        ll temp=n/2;
        
        fo(i,n+1)val[i]=0;
        val[temp]=temp*2;
        //ll m1[n+1];
        fo(i,n+1)m1[i]=0;
        for(int i=n;i>=2;i--){
            ans[i]=temp;
            m1[val[temp]]=1;
            for(;temp>1;temp--){
                //flag=0;
                while(m1[val[temp]]!=0){
                    //if(m1[val[temp]])
                    val[temp]-=temp;
                    if(val[temp]==temp || val[temp]==0)break;
                }
                if(val[temp]!=temp || val[temp==0])break;
                else{
                    val[temp-1]=((ll)n/(temp-1))* (temp-1);
                    val[temp-1]=min(val[temp-1], (temp-1)*(temp-1));
                }
            }
            if(temp==1)break;
        }
        for(int i=2;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}