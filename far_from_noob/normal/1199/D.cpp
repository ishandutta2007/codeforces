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
        cin>>n;
        ll a[n];
        fo(i,n)cin>>a[i];
        cin>>q;
        ll  update[n],mini[q],temp=0;
        fo(i,n)update[i]=0;
        fo(i,q)mini[i]=0;
        fo(i,q){
            cin>>x;
            if(x==1){
                cin>>k>>m;
                update[k-1]=i;
                a[k-1]=m;
            }
            if(x==2){
                cin>>m;
                mini[i]=m;
                
            }
        }
        ll dmin[q];
        dmin[q-1]=mini[q-1];
        for(int i=q-2;i>=0;i--){
            dmin[i]=max(dmin[i+1],mini[i]);
        }
        fo(i,n){
            a[i]=max(a[i],dmin[update[i]]);
        }
        fo(i,n)cout<<a[i]<<" ";
    }

    return 0;
}