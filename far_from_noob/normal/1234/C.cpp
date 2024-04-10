#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        ll a[2][n];
        fo(i,n)a[0][i]=s1[i]-'0';
        fo(i,n)a[1][i]=s2[i]-'0';
        ll temp=1;
        ll x=0,y=0;
        ll flag=0;
        while(1){
            if(temp==1){
                if(a[x][y]==1||a[x][y]==2)y++;
                else {
                    temp=2;
                    x=1-x;
                }
            }
            else {
                if(a[x][y]==1||a[x][y]==2){cout<<"NO";flag=1;break;}
                else{
                    temp=1;
                    y++;
                }
            }
            if(y>=n && x==0){cout<<"NO";flag=1;break;}
            if(y==n && x==1)break;
        }
        if(flag==0)cout<<"YES";
        cout<<endl;
        
    }

    return 0;
}