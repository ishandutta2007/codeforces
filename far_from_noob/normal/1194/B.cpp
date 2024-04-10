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
    cin>>t;
    //t=1;
    while(t--){
            flag=0;
        cin>>n>>m;
        char a[n][m];
        fo(i,n)fo(j,m)cin>>a[i][j];
        ll max1=0,max2=0;
        fo(i,n){
            ll count=0;
            fo(j,m)if(a[i][j]=='*')count++;

            if(count>max1)max1=count;

        }
        vector<ll>v;
        fo(i,n){
            ll count=0;
            fo(j,m)if(a[i][j]=='*')count++;

            if(count==max1)v.push_back(i);

        }

        fo(i,m){
            ll count=0;
            fo(j,n)if(a[j][i]=='*')count++;

            if(count>max2)max2=count;

        }
        fo(i,m){
            ll count=0;
            fo(j,n)if(a[j][i]=='*')count++;

            if(count==max2){
                fo(j,v.size()){
                    if(a[v[j]][i]=='.')flag=1;
                }
            }

        }
        cout<<n+m-max1-max2-flag<<endl;


    }

    return 0;
}