#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N=5e5+5;
const ll MOD=1e9+7;
ll mypow(ll a,ll b)
{
    if(!b) return 1;
    ll t=mypow(a,b/2);
    if(b%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}
ll n,k,sq,res=1,dp[2][55],inv[101],inv2[101];
vector<P> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ct=1;
    for(int i=1;i<=100;i++){
        ct*=2LL;
        inv[i]=mypow(ct,MOD-2);
        inv2[i]=mypow(i,MOD-2);
    }
    cin>>n>>k;
    sq=sqrt(n)+20;
    for(int i=2;i<=sq;i++){
        if(n%i) continue;
        int res=0;
        while(n%i==0){
            n/=i;
            res++;
        }
        v.push_back(P(i,res));
    }
    if(n!=1) v.push_back(P(n,1));
    for(int i=0;i<v.size();i++){
        //cout<<v[i].first<<" "<<v[i].second<<endl;
        int t=v[i].second,c=0;
        for(int j=0;j<=t;j++) dp[0][j]=dp[1][j]=0;
        dp[0][t]=1;
        for(int tt=1;tt<=k;tt++){
            ll sum=0;
            for(int j=t;j>=0;j--){
                (sum+=(dp[c][j]*inv2[(j+1)]%MOD))%=MOD;
                dp[1-c][j]=sum;
            }
            c=1-c;
        }
        ll now=0,c2=1;
        for(int j=0;j<=t;j++){
            (now+=c2*dp[c][j])%=MOD;
            //cout<<j<<" : "<<dp[c][j]<<" "<<now<<endl;
            (c2*=(ll)v[i].first)%=MOD;
        }
        //cout<<now<<" "<<v[i].second<<" "<<inv[v[i].second]<<" "<<2*inv[v[i].second]<<endl;
        //(now*=inv[v[i].second])%=MOD;
        //cout<<now<<endl;
        (res*=now)%=MOD;
    }
    cout<<res;
    return 0;
}