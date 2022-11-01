#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,x,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}
ll logg(ll a){
    if(pow(2,(ll)(log2(a))) == a)return log2(a);
    else return (ll)log2(a)+1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
        //cout<<logg(8);
        cin>>n>>k;
        if(8*k/n > 40){cout<<0;return 0;}
        k=(ll)pow(2,(ll)(8*k)/n);
        ll a[n];
        fo(i,n)
        cin>>a[i];
        ll b[n];
        sort(a,a+n);
        map<ll,ll>m1;
        ll diff=0;
        fo(i,n){if(m1[a[i]]==0)b[diff]=a[i],diff++;m1[a[i]]++;}
        ll mini=mod;
        
        //cout<<diff<<endl;
        if(diff<=k){cout<<0;return 0;}
        ll ab[diff-k+1];
        ab[diff-k]=0;
        //cout<<m1[b[diff-1]]<<endl;
        for(int i=diff-1;i>=diff-k;i--)ab[diff-k]+=m1[b[i]];
        mini=n-ab[diff-k];
        //cout<<mini<<endl;
        for(int i=diff-k-1;i>=0;i--){
            ab[i]=ab[i+1]+m1[b[i]]-m1[b[i+k]];
            mini=min(mini,n-ab[i]);
        }
        cout<<mini<<endl;
        
        
    }
 
    return 0;
}