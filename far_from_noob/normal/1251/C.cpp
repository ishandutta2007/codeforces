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
    cin>>t;
    //t=1;
    while(t--){
        string s;
        cin>>s;
        vector<char>v1;
        vector<char>v2;
        ll temp=0;
        fo(i,s.size()){
            if((s[i]-'0')%2==0)v2.pb(s[i]);
            else v1.pb(s[i]);
            
            
        }
        ll temp1=0,temp2=0;
        while(temp1<v1.size()&&temp2<v2.size()){
            if(v1[temp1]>v2[temp2]){
                cout<<v2[temp2];
                temp2++;
            }
            else cout<<v1[temp1],temp1++;
        }
        for(int i=temp1;i<v1.size();i++)cout<<v1[i];
        for(int i=temp2;i<v2.size();i++)cout<<v2[i];
        cout<<endl;
        //cout<<s<<endl;
        
    }

    return 0;
}