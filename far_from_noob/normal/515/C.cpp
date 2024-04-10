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
        char c[n];
        fo(i,n)cin>>c[i];
        ll a[n];
        fo(i,n)a[i]=c[i]-'0';
        ll c2=0,c3=0;
        sort(a,a+n);
        for(int i=n-1;i>=0;i--){
            if(a[i]>=7){
                cout<<7;
                if(a[i]==9)c3+=2,c2++;
                if(a[i]==8)c2+=3;
            }
            else if(a[i]>=5){
                cout<<5;
                if(a[i]==6)c3++;
            }
            else if(a[i]==4)c3++,c2+=2;
            else if(a[i]==3)c3++;
            else if(a[i]==2)c2+=1;
            
        }
        fo(i,c3)cout<<3;
        fo(i,c2)cout<<2;
        
    }

    return 0;
}