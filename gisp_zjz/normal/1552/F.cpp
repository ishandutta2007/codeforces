#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
int n,s[maxn];
ll x[maxn],y[maxn],dp[maxn],sum[maxn],ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld%lld%d",&x[i],&y[i],&s[i]);
    ans=x[n]+1;
    for (int i=1;i<=n;i++){
        int l=0,r=i;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (x[mid]>y[i]) r=mid; else l=mid;
        }
        dp[i]=x[i]-y[i]+sum[i-1]-sum[l];
        dp[i]=(dp[i]%M+M)%M;
        sum[i]=(sum[i-1]+dp[i])%M;
        if (s[i]) ans=(ans+dp[i])%M;
    }
    printf("%lld\n",ans%M);
}