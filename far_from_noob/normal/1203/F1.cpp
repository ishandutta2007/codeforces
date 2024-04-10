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
        ll r;
        cin>>n;
        cin >> r;
        pair<ll,ll>p[n];
        ll temp1=0,temp2=0;
        pair<ll,ll>p1[n];
        fo(i,n){
            ll a,b;
            cin>>a>>b;
            if(b>=0){
                p[temp1]=make_pair(a,b);
                temp1++;
            }
            else{
                p1[temp2]=make_pair(a+b,b);
                temp2++;
            }
        }
        sort(p,p+temp1);
        sort(p1,p1+temp2);
        
        fo(i,temp1){
            if(r>=p[i].first){
                r+=p[i].second;
            }
            else {flag=1;break;}
        }
        if(flag==1){cout<<"NO";return 0;}
        fo(i,temp2){
            if(r>=p1[temp2-1-i].first - p1[temp2-1-i].second){
                r+=p1[temp2-1-i].second;
            }
            else {flag=1;break;}
        }
        if(flag==0 && r>=0)cout<<"YES";
        else cout<<"NO";
    }

    return 0;
}