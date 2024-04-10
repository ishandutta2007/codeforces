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
        ll u,v;
        cin>>u>>v;
        ll u1=u,u2=v;

        vector<ll>v1,v2;
        for(int i=60;i>=0;i--){
            if(v>=(ll)pow(2,i))v1.pb(1),v-=(ll)pow(2,i);
            else v1.pb(0);
        }
        for(int i=60;i>=0;i--){
            if(u>=(ll)pow(2,i))v2.pb(1),u-=(ll)pow(2,i);
            else v2.pb(0);
        }
        ll carry=0;
        vector<ll>ans;
        
        flag=0;
        for(int i=0;i<=60;i++){
            if(carry==0){
                if(v1[i]==0){
                    if(v2[i]==0)ans.pb(0);
                    else{flag=1 ; break;}
                }
                else if(v1[i]==1){
                    if(v2[i]==0)ans.pb(0),carry=1;
                    else ans.pb(1);
                }
            }
            else{
                if(v1[i]==0){
                    if(v2[i]==0)ans.pb(2),carry=0;
                    else ans.pb(1),carry=1;
                }
                else{
                    if(v2[i]==0)ans.pb(2),carry=1;
                    else {flag=1 ; break;}
                }
            }
        }
        v=u2;
        u=u1;
        if(carry!=0){flag=1;}
        ll ans1=0,ans2=0,ans3=0;
        if(flag==1){
            if(v<u|| (v-u)%2==1)cout<<-1;
            else{
                cout<<3<<endl<<u <<" "<<(v-u)/2<<" "<<(v-u)/2;
            }
            return 0;
        }
        fo(i,61){
            if(ans[i]>=1)ans1+=(ll)pow(2,60-i);
            if(ans[i]>=2)ans2+=(ll)pow(2,60-i);
            if(ans[i]>=3)ans3+=(ll)pow(2,60-i);
        }
        ll count=0;
        if(ans1>0)count++;
        if(ans2>0)count++;
        if(ans3>0)count++;
        cout<<count<<endl;
        if(count>=1)cout<<ans1<< " ";if(count>=2)cout<<ans2<< " ";if(count>=3)cout<<ans3<< " ";

    }

    return 0;
}