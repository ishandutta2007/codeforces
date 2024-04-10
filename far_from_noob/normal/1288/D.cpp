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
        ll a[n][m];
        fo(i,n)fo(j,m)cin>>a[i][j];
        ll kk=(ll)pow(2,m);
        kk--;
        ll maxi[kk+1],index[kk+1];
        maxi[0]=0;
        //ll val[n][kk+1];
        fo1(i,kk){
            k=i;
            ll temp[m];
            for(int j=m-1;j>=0;j--){
                if(k/(ll)pow(2,j)==1){
                    temp[j]=1;
                    k-=(ll)pow(2,j);
                }
                else temp[j]=0;
            }
            maxi[i]=0;
            index[i]=0;
            fo(j,n){
                ll mini=mod;
                fo(l,m){
                    //if(i==3&&j==0)cout<<temp[l];
                    if(temp[l]==1){
                        mini=min(mini,a[j][l]);
                    }
                }
                //val[j][i]=mini;
                if(maxi[i]<mini){
                    maxi[i]=mini;
                    index[i]=j;
                }
            }
        }
        ll maxn=0;
        pair<ll,ll>ans;
        ans=mp(index[kk]+1,index[kk]+1);
        //cout<<maxi[3]<<index[5]<<endl;
        //cout<<val[4][kk-5]<<val[0][5];
        //cout<<ans.fi<<" "<<ans.se;
        fo1(i,kk-1){
            if(maxn<min(maxi[i],maxi[kk-i])){
                maxn=min(maxi[i],maxi[kk-i]);
                ans=mp(index[i]+1,index[kk-i]+1);
            }
        }
        cout<<ans.fi<<" "<<ans.se<<" ";


        
    }

    return 0;
}