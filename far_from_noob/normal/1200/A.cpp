#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
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
        cin>>n;
        string s;
        cin>>s;
        ll a[10];
        fo(i,10)a[i]=0;
        ll left=0;
        ll right=9;
        fo(i,n){
            //ll temp=0;
            if(s[i]=='L'){
                fo(j,10){
                    if(a[j]==0){a[j]=1;break;}
                }
            }
            else if(s[i]=='R'){
                for(int j=9;j>=0;j--){
                    if(a[j]==0){a[j]=1;break;}
                }
            }
            else {
                a[s[i]-'0']=0;
            }
            
        }
        fo(i,10)cout<<a[i];
    }

    return 0;
}