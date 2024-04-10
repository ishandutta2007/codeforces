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
        for(int i=n;i<=m;i++){
            ll temp=0;
            map<ll,ll>m1;
            int p=i;
            ll flag=0;
            for(int d=100000;d>=1;d/=10){
                if(p/d 
                >=1){
                    temp=1;
                }
                if(temp==1){
                    m1[p/d]++;
                    //cout<<p/d<< " ";
                    if(m1[p/d]==2){
                        flag=1;
                        break;
                    }
                    p=p- (p/d) * d;
                }
            }
            if(flag==0){
                cout<<i;return 0;
                
            }
        }
        cout<<-1;
    }

    return 0;
}