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
    //cin>>t;
    t=1;
    while(t--){
        
        string s;
        cin>>s;
        ll temp=0;
        vector<char>v;
        fo(i,s.size()){
            if(s[i]=='a')temp++;
            else v.push_back(s[i]);
        }
        ll l=v.size();
        if(l%2==1){cout<< ":(";return 0;}
        else {
            for(int i=0;i< l/2;i++){
                if(v[i]!=v[i+ l/2])flag=1;
            }
        }
        fo(i,s.size()){
            if(s[i]=='a')if(i>=temp+ l/2)flag=1;
        }
        if(flag){cout<< ":(";return 0;}
        else {
            fo(i,temp+ l/2)cout<<s[i];
        }
        
    }

    return 0;
}