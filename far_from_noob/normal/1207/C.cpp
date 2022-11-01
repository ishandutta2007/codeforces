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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        ll a,b;
        cin>>a>>b;
        string s1;
        cin>>s1;
        char s[n+1];
        s[0]='0',s[n]='0';
        for(int i=1;i<n;i++){
            s[i]= max(s1[i-1],s1[i]);
        }
        ll ans=n*a + (n+1)*b;
        ll temp=0,ij=0;
        fo(i,n+1){
            if(s[i]=='1'){
            
                if(flag==0){
                if(ij==0)ans+=2*a;
                else ans+=min((temp)*b , a*2);
                }
                flag=1;
                temp=0;
                ans+=b;
                ij=1;
            }
            else if(s[i]=='0' && ij==1){
                if(flag==1){
                    flag=0;
                }
                
                    temp++;
                
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}