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
        cin>>n;
        //if(n==3){cout<<-1;return 0;}
        ll myprime;
        for(int i=0;i<1000;i++){
            if(prime[i]>=n){myprime=prime[i];break;}
        }
        cout<<myprime<<endl;
        for(int i=1;i<=n;i++)cout<<i<<" "<<(i)%n+1<<endl;
        ll temp=0,count=0;
        myprime=myprime-n;
        while(myprime>count){
            if(myprime==1){cout<<temp+1<< " "<<temp+3<<endl;break;}
            else {
                cout<<temp+1<< " "<<temp+3<<endl<<temp+2<< " "<<temp+4<<endl;
                temp+=4;
                myprime-=2;
            }
            
            
        }
        
        
        
    }

    return 0;
}