#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fo(i,n) for(int i=0;i<n;i++)
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
        cin>>n>>m;
        ll a[n][m];
        fo(i,n)fo(j,m)a[i][j]=0;
        fo(i,n){
            ll b;
            cin>>b;
            fo(j,b){
                if(a[i][j]==-1){
                    cout<<0;return 0;;
                }
                a[i][j]=1;
            }
            if(b<m){
                if(a[i][b]==1){
                    cout<<0;return 0;;
                }
                a[i][b]=-1;
            }
        }
        fo(i,m){
            ll b;
            cin>>b;
            fo(j,b){
                if(a[j][i]==-1){
                    cout<<0;return 0;;
                }
                a[j][i]=1;
            }
            if(b<n){
                if(a[b][i]==1){
                    cout<<0;return 0;;
                }
                a[b][i]=-1;
            }
        }
        ll count=0;
        fo(i,n)fo(j,m)if(a[i][j]==0)count++;
        //cout<<count<<endl;
        cout<<po(2,count,1,1,2);
    }

    return 0;
}