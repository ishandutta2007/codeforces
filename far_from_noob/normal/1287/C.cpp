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
        ll odd=0,even=0;
        vector<ll>v1,v2,v3;
        ll a[n];
        fo(i,n){cin>>a[i];if(a[i]%2==1)odd++;else if(a[i]>0)even++;}
        flag=1;
        ll temp=1;
        ll count=0;
        ll lastnz=-1;
        ll count1=0,ans=0;
        fo(i,n){
            if(a[i]==0){
                count++;
            }
            else {
                if(lastnz==-1){
                    flag=a[i];
                    lastnz=a[i];
                    temp=a[i];
                    if(i>0)count1=count;
                    count=0;
                }
                else if(a[i-1]==0){
                    //temp=a[i];
                    if(lastnz%2==0 && a[i]%2==0)v2.pb(count);
                    else if(lastnz%2==1 && a[i]%2==1)v1.pb(count);
                    else v3.pb(count);

                }
                else {
                    if((a[i-1]+a[i])%2==0);
                    else ans++;
                }
                count=0;
                lastnz=a[i];
            }
        }
        //cout<<v1.size()<<v2.size()<<v3.size();
         even=n/2 -even;
         odd=n-n/2-odd;
         ans+=v3.size();
         sort(all(v1));
         sort(all(v2));
         if(odd+even==n){if(n==1)cout<<0; else cout<<1; return 0;}
         fo(i,v1.size()){
            if(odd>=v1[i])odd-=v1[i];
            else{
                ans+=2*(v1.size()-i);
                break;
            }
         }
         //cout<<ans;
         if(flag%2==1&& count1>0){
                    if(odd>=count1)odd-=count1;
                    else ans++;
                }
        //cout<<ans;
                if(lastnz%2==1&& count>0){
                    if(odd>=count)odd-=count;
                    else ans++;
                }
        
         fo(i,v2.size()){
            if(even>=v2[i])even-=v2[i];
            else{
                ans+=2*(v2.size()-i);
                
                break;
            }
         }
         if(flag%2==0&& count1>0){
                    if(even>=count1)even-=count1;
                    else ans++;
                }
                if(lastnz%2==0&& count>0){
                    if(even>=count)even-=count;
                    else ans++;
                }
         cout<<ans<<endl;

        
    }

    return 0;
}