
 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll mod=998244353;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    //t=1;
    while(t--){
        flag=0;
        cin>>n;
        ll xl=-100000,yl=-100000,xu=100000,yu=100000;
        fo(i,n){
            ll x,y;
            cin>>x>>y;
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a==0  )xl=max(x,xl);
            if(c==0  )xu=min(xu,x);
            if(b==0  )yu=min(yu,y);
            if(d==0  )yl=max(yl,y);
            if(xl>xu ){flag=1;}
            if(yl>yu){flag=1;}
        }
        if(flag)cout<<0<< endl;
        else cout<<1<< " "<< xu<< " "<< yu<<endl;
    }
 
    return 0;
}