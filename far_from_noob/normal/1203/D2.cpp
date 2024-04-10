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
        string s;
        string t;
        cin>>s;
        cin>>t;
        ll l=t.size();
        ll a[l+1];
        ll b[l+1];
        fo(i,l+1)a[i]=-1;
        fo(i,l+1)b[i]=s.size();
        ll temp=0,j=0;
        fo(i,l+1){
            
            while(temp<i){
                if(s[j]==t[temp]){
                    temp++;
                    a[i]=j;
                }
                j++;
            }
        }
            //cout<<a[i]<<endl;
            temp=0,j=0;
        fo(i,l+1){
            while(temp<i){
                if(s[s.size()-j]==t[l-1-temp]){
                    temp++;
                    b[l-i]=s.size()-j;
                }
                j++;
            }
            //cout<<b[i]<<endl;
        }
        ll mini=0;
        fo(i,l+1){
            mini=max(b[i]-a[i]-1,mini);
        }
        cout<<mini;
    }

    return 0;
}