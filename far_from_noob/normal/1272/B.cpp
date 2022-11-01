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
        string s;

        cin>>s;
        ll l=0,r=0,u=0,d=0;
        fo(i,s.size()){
            if(s[i]=='L')l++;
            else if(s[i]=='D')d++;
            else if(s[i]=='U')u++;
            else if(s[i]=='R')r++;
        }
        if(min(l,r)>0 && min(u,d)>0){
        cout<<2*min(l,r)+2*min(u,d)<<endl;
        fo(i,min(l,r))cout<<"L";
        fo(i,min(d,u))cout<<"U";
        fo(i,min(l,r))cout<<"R";
        fo(i,min(d,u))cout<<"D";
        cout<<endl;
        }
        else if(min(l,r)==0&& min(u,d)==0)cout<<0<<endl;
        else{
            cout<<2<<endl;
            if(min(l,r)>0)cout<<"LR"<<endl;
            else cout<<"UD"<<endl;
        }


    }

    return 0;
}