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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll a[n],temp=0;
    pair <int,int>pa[n];
    vector<pair<int,int>>v;
    fo(i,n)a[i]=n-i;
    fo(j,m){
        ll l ,r;
        cin>>t>>l>>r;
        if(t==1){
            pa[temp]=make_pair(l,r);
            temp++;
            
        }
        
        else {
            pair<int,int>p;
            p=make_pair(l,r);
            v.push_back(p);
            
        }
    }
    sort(pa,pa+temp);
    //cout<<pa[0].first<<pa[0].second;
    for(int i=0;i<temp;i++){
        for(int j=pa[i].first;j<pa[i].second;j++){
            a[j]=a[pa[i].first -1];
        }
    }
    //cout<<v[0].first<<v[0].second;
    //fo(i,n)cout<<a[i]<<" ";
    for(int i=0;i<v.size();i++){
        ll temp=0;
        for(int j=v[i].first-1;j<v[i].second-1;j++){
            if(a[j]>a[j+1]){temp=1;break;}
        }
        if(temp==0){cout<<"NO";return 0;}
    }
    cout<<"YES"<<endl;
    fo(i,n)cout<<a[i]<<" ";
    
    
    return 0;
}