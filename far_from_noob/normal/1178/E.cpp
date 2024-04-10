#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=998244353;
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
    vector<ll>prime;
    map<ll,ll>isprime;
    for(int i=2;i<2000;i++){
        if(isprime[i]==0){
            prime.push_back(i);
            for(int j=i;j<2000;j+=i)isprime[j]=1;
        }
    }
    t=1;
    while(t--){
        string s;
        cin>>s;
        ll l=s.size(),temp=0;
        vector<char>v;
        while(l>=4){
            if(s[temp]==s[s.size()-1-temp])v.push_back(s[temp]);
            else if (s[temp]==s[s.size()-1-temp-1])v.push_back(s[temp]);
            else v.push_back(s[temp+1]);
            temp+=2;
            l=l-4;
        }
        fo(i,v.size())cout<<v[i];
        if(l>0)cout<<s[temp];
        for(int i=v.size()-1;i>=0;i--)cout<<v[i];
        
    }

    return 0;
}