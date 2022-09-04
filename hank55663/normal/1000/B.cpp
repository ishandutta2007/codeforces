#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005];
    a[0]=0;
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    a[n+1]=m;
    int pre[100005];
    pre[0]=0;
    for(int i=1;i<=n;i+=2){
        pre[i]=pre[i-1]+a[i]-a[i-1];
        pre[i+1]=pre[i];
    }
    int suf[100005];
    suf[n]=0;
    int start;
    if(n%2==1){
        start = n-1;
    }
    else{
        start =n-2;
        suf[n-1]=0;
    }
    for(int i=start;i>=0;i-=2){
        suf[i]=suf[i+1]+a[i+2]-a[i+1];
        if(i!=0)
        suf[i-1]=suf[i];
    }
    int ans=0;
    for(int i=1;i<=n+1;i+=2)
    ans+=a[i]-a[i-1];
    for(int i=0;i<=n;i++){
        if(a[i+1]!=a[i]+1)
        ans=max(ans,pre[i]+suf[i]+a[i+1]-a[i]-1);
     //   printf("%d %d %d\n",pre[i],suf[i],pre[i]+suf[i]+a[i+1]-a[i]-1);
    }
    printf("%d\n",ans);
}