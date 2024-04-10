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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        ll a[n];
        ll m1[201];
        fo(i,201)m1[i]=0;
        ll ans=0;
        fo(i,n)cin>>a[i],m1[a[i]]++;
        for(int i=1;i<201;i++){
            ll m2[201];
            fo(i,201)m2[i]=0;
            ll maxi=0;
            ll l, r;

            ll c1=0,c2=0;
            fo(j,n){
                if(c1==m1[i]/2){l=j ; break;}
                else {
                    if(a[j]==i)c1++;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(c2==m1[i]/2){r=j ; break;}
                else {
                    if(a[j]==i)c2++;
                }
            }
            for(int j=l;j<=r;j++){
                m2[a[j]]++;
                maxi=max(maxi,m2[a[j]]);
            }
            //cout<<maxi<<l<<r<<m1[i]/2;
            for(int j=m1[i]/2; j>=0; j--){
                ans=max(ans, 2*j + maxi);
                if(j==0)break;
                l--;
                while(l>=0 ){
                    m2[a[l]]++;
                    maxi=max(maxi,m2[a[l]]);
                    if(l==0)break;
                    if(a[l-1]==i)break;
                    l--;

                }
                r++;
                while(r<n ){
                    m2[a[r]]++;
                    maxi=max(maxi,m2[a[r]]);
                    if(r==n-1)break;
                    if(a[r+1]==i)break;
                    r++;

                }

            }


        }
        cout<<ans<<endl;
        
    }

    return 0;
}