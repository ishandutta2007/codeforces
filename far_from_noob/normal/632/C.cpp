#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,q,x,flag=0;
vector<ll>v[1000000];
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
    cin>>n;
    string s[n];
    fo(i,n)cin>>s[i];
    ll temp=0;
    fo(i,n){
        ll kk=s[i].size();
        if(temp<kk)temp=kk;
    }
    temp*=2;
    //cout<<temp;
    vector<char>v[n];
    fo(i,n){
        ll sl=s[i].size();
        //cout<<sl<<endl;
        for(int j=0;j<temp;j++)v[i].push_back(s[i][j%sl]);
    }
    //fo(i,n)cout<<v[i].size()<<"fuck"<<endl;
    pair<vector<char>,ll>p[n];
    fo(i,n){
        p[i]=make_pair(v[i],i);
    }
    sort(p,p+n);
    fo(i,n){
    ll kk =p[i].second;
    cout<<s[kk];

    }






    return 0;
}