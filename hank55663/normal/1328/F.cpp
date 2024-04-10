#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL pre[200005];
LL a[200005];
LL cal(int l,int r){
    int mid=(l+r)/2;
    return pre[r]-pre[mid]-a[mid]*(r-mid) + a[mid]*(mid-l+1)-pre[mid]+pre[l-1];
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1;i<=n-k+1;i++){
        if(a[i]==a[i+k-1]){
            printf("0\n");
            return 0;
        }
    }
    for(int i = 1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    LL ans=min(a[k]*k-pre[k],pre[n]-pre[n-k]-a[n-k+1]*k);
    for(int tt=0;tt<2;tt++){
    for(int i = 1;i<=k;i++){
        int it=upper_bound(a+1,a+n+1,a[i])-a;
        ans=min(ans,a[i]*i-pre[i]+pre[n]-pre[i]-a[i]*(n-i)-(n-max(k,it)));
    }
    for(int i = k+1;i<=n;i++){
        int it=lower_bound(a+1,a+n+1,a[i])-a-1;
        ans=min(ans,a[i]*i-pre[i]-min(i-k,it));
    }
    reverse(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        a[i]=-a[i];
        pre[i]=pre[i-1]+a[i];
    }

    }
    printf("%lld\n",ans);
}