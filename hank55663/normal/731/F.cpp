#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
LL sum[400005];
int main() {
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum[a[i]]++;
    }
    for(int i = 1;i<=400005;i++)
        sum[i]+=sum[i-1];
    sort(a,a+n);
    LL ans=0;
    for(int i=0;i<n;i++){
        if(i==0||a[i]!=a[i-1]){
            LL tot=0;
            for(int j = 1;a[i]*j<=200000;j++){
                tot+=(LL)(sum[a[i]*(j+1)-1]-sum[j*a[i]-1])*a[i]*j;
            }
           // printf("%lld\n",tot);
            ans=max(ans,tot);
        }
    }
    printf("%lld\n",ans);
    return 0;
}