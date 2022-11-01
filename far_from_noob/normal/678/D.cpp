#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=1000000007;
ll n,k,t,m,p,q,a,b,x,flag=0;

ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;
        ans%=mod;
        ans1=ans1*ans1;
        ans1%=mod;
        n=n-temp;
        temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //cout<<po(2,78,1,1,2);
}
ll sumn(ll a,ll low,ll high){
    if(high==low)return a;
    if((high-low)%2==1){
    ll mid=(high+low)/2;
    return (((1+po(a,mid,1,1,a))%mod) * sumn(a,low,mid))%mod;
    }
    else {
        ll mid=(high+low)/2;
        return ((((1+po(a,mid,1,1,a))%mod) * sumn(a,low,mid-1)) %mod  +  po(a,mid,1,1,a)  )%mod;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
            cin>>a>>b>>n>>x;
            if(n==1){cout<<((a*x)%mod +b )%mod ; return 0;}
             if(a==1){cout<<(x + b*(n%mod))%mod;return 0;}
            //ll power[50];
            //fo(i,49)power[i+1]=po(a,i+1,1,1,a);
            ll temp= sumn(a,1,n-1) +1;
            //cout<<sumn(3,1,5)<<endl;

            //cout<<temp<<endl;
            //cout<<po(3,9,1,1,3);
            //ll countans=0;


            cout<< ((po(a,n,1,1,a) * x)%mod + (( temp* b)%mod ))%mod;
    }

    return 0;
}