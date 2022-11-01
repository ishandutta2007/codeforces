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
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
        ll x,y,c;
        cin>>n>>x>>y>>c;
        m=n;
        ll l=0,r=mod;
        while(l!=r){
            
            ll mid=(l+r)/2;
            //if(r<1000)cout<<l<<" "<<r<<" "<<mid<<endl;
            ll count=0;
            if(mid<=x-1){count+= (mid)*(mid);}
            else count=(mid)*(mid)- (mid+1-x)*(mid+1-x);
                
            ll x1=n-x+1;
 
            if(mid<=x1-1){count+= (mid)*(mid);}
            else count+=(mid)*(mid)- (mid+1-x1)*(mid+1-x1);
 
            count+=y+mid- y+mid +1;
            //if(mid==3)cout<<count<<endl;
            if(mid>y-1)count-=(mid+1-y)*(mid+1-y);
            //if(mid==3)cout<<count<<endl;
            ll y1=m-y+1;
            if(mid>y1-1)count-=(mid+1-y1)*(mid+1-y1);
            //if(mid==4)cout<<count<<endl;
 
            if(mid>x-1+y-1){
                ll kk=mid-(x-1+y-1)-1;
                count+=(kk)*(kk+1)/2;
            }
 
            if(mid>x1-1+y-1){
                ll kk=mid-(x1-1+y-1)-1;
                count+=(kk)*(kk+1)/2;
            }
            //if(mid==4)cout<<count<<endl;
            if(mid>x-1+y1-1){
                ll kk=mid-(x-1+y1-1)-1;
                count+=(kk)*(kk+1)/2;
            }
            //if(mid==4)cout<<count<<endl;
            if(mid>x1-1+y1-1){
                ll kk=mid-(x1-1+y1-1)-1;
                count+=(kk)*(kk+1)/2;
            }
 
            //if(mid==4)cout<<count<<endl;
            if(count < c)l=mid+1;
            else r=mid;
            
 
 
 
        }
        cout<<l;
 
        
    }
 
    return 0;
}