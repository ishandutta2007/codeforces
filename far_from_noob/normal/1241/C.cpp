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
        cin>>n;
        ll p[n];
        fo(i,n)cin>>p[i];
        ll a,b,x,y;
        cin>>x>>a>>y>>b;
        cin>>k;
        sort(p,p+n);
        ll pr[n+1];
        pr[0]=0;
        pr[1]=p[n-1];
        fo1(i,n-1){
            pr[i+1]=pr[i]+p[n-1-i];
        }
        flag=0;
        ll lcm=a*b/__gcd(a,b);
        fo1(i,n){
            if(x>=y){
            if(pr[i/lcm]*y+ pr[i/a ]*x +(pr[i/a + i/b - i/lcm]-pr[i/a])*y >=k*100)
                {flag=1;cout<<i<<endl;break;}
            }
            else{
                if(pr[i/lcm]*x+ pr[i/b ]*y +(pr[i/a + i/b - i/lcm]-pr[i/b])*x >=k*100)
                {flag=1;cout<<i<<endl;break;}
            }
        }
        if(flag==0)cout<<-1<<endl;
    }

    return 0;
}