#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    t=1;
    while(t--){
            char a1,b,c;
            char x,y,z,g;
            int a[3];
            cin>>x>>a1>>y>>b>>z>>c;
            a[0]=x-'a';
            a[1]=y-'a';
            a[2]=z-'a';

            //cin>>x>>a1>>y>>b>>z>>c;
            if(a1==b && b==c){
                sort(a,a+3);
                if(a[0]==a[2])cout<<0;
                else if(a[0]==a[1] || a[2]==a[1])cout<<1;
                else if(a[1]-a[0]==1 && a[2]-a[1]==1)cout<<0;
                else if(a[1]-a[0]==1||a[1]-a[0]==2||a[2]-a[1]==1||a[2]-a[1]==2)cout<<1;
                else cout<<2;
            }
            else if(a1==b)if(abs(y-x)<3)cout<<1;else cout<<2;
            else if(a1==c)if(abs(z-x)<3)cout<<1;else cout<<2;
            else if(c==b)if(abs(y-z)<3)cout<<1;else cout<<2;
            else cout<<2;
    }

    return 0;
}