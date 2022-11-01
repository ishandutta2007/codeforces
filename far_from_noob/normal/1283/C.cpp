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
        ll b[n+1];
        fo(i,n+1)b[i]=0;
        vector<ll>v;
        vector<ll>v1;
        fo(i,n){cin>>a[i],b[a[i]]=1;
            if(a[i]==0)v.pb(i+1);
        }
        fo1(i,n){
            if(b[i]==0)v1.pb(i);
            //cout<<b[i];
        }
        //fo(i,v.size())cout<<v1[i];
        ll temp=0;
        vector<ll>vv;
        fo(i,v.size()){
            if(b[v[i]]==0)vv.pb(v[i]);
        }
        if(vv.size()>1)fo(i,vv.size()){
            a[vv[i]-1]=vv[(i+1+vv.size())%vv.size()];
            b[vv[i]]=1;
        }
        else if(vv.size()==1){
            //cout<<" wfs";
            fo(i,v1.size()){
                if(vv[0]!=v1[i]){
                    a[vv[0]-1]=v1[i];
                    b[v1[i]]=1;
                    break;
                }
            }
        }
        fo(i,v.size()){
            if(a[v[i]-1]==0){
                if(b[v1[temp]]==0){
                    a[v[i]-1]=v1[temp];
                    temp++;
                }
                else temp++,i--;
            }
        }
        fo(i,n)cout<<a[i]<<" ";
        


        
    }

    return 0;
}