#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll k;
        cin>>k;
        string s[n];
        fo(i,n)cin>>s[i];
        ll a[k][5];
        fo(i,k)fo(j,5)a[i][j]=0;
        fo(i,n){
            fo(j,k){
                a[j][s[i][j]-'A']++;
            }
        }
        ll b[k];
        fo(i,k){sort(a[i], a[i]+ 5);b[i]=a[i][4];}
        ll c[k];
        ll ans=0;
        fo(i,k){
            cin>>m;
            ans+=m*b[i];
        }
        cout<<ans;
        
        
    }

    return 0;
}