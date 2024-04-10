#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    LL a[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]*=(LL)(n-i)*(i+1);
   //     printf("%lld ",a[i]);
    }
 //   printf("\n");
    sort(a,a+n);
    LL b[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&b[i]);
    }
    sort(b,b+n);
    reverse(b,b+n);
    LL ans=0;
    for(int i = 0;i<n;i++){
        ans+=a[i]%mod*b[i]%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
}