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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        ll a[n];
        pair<ll,ll>p[n];
        ll total=0;
        fo(i,n){cin>>a[i];p[i]=make_pair(a[i],i);total+=a[i];}
        sort(p+1,p+n);
        ll temp=a[0],j=1;
        while(temp*2<=total){
            if(a[0]>=2*p[j].first){
                temp+=p[j].first;
                j++;
            }
            else break;
            
        }
        if(temp*2>total){
            cout<< j<<endl;
            cout<<"1 ";
            for(int i=1;i<j;i++)cout<<p[i].second+1<<" ";
            
        }
        else cout<<0;
        
        
        
    }

    return 0;
}