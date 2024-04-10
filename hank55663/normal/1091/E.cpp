
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int a[500005];
LL sum[500005];
LL l[500005],r[500005],k[500005];
int rr[500005];
int main(){
    int n;
    scanf("%d",&n);
    LL ssum=0;
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]),ssum+=a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=0)
        rr[a[i]-1]=i;
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(rr[i]==0)rr[i]=rr[i+1];
      //  printf("%d ",rr[i]);
    }
    for(int i=1;i<=n;i++){
        l[i]=sum[i]-sum[0];
        r[i]=sum[n]-sum[i]+(LL)i*(i-1)-max(sum[rr[i]]-sum[i],0ll);
        k[i]=max(rr[i]-i,0);
        r[i]+=k[i]*i;
    //    printf("%lld %lld %lld\n",l[i],r[i],k[i]);
    }
    int lans=0,rans=n;
    for(int i=1;i<=n;i++){
        if(r[i]<l[i]-i){
 //           printf("r:%lld l:%lld\n",r[i],l[i]-i);
            printf("-1\n");
            return 0;
        }
        lans=max((LL)lans,l[i]-r[i]);
        LL ll=l[i]-i;
        rans=min(r[i]-ll+k[i]+i,(LL)rans);
    }
   // printf("%d %d\n",lans,rans);
    if((lans+ssum)%2==1)
    lans++;
    if(lans>rans){
        printf("-1\n");
        return 0;
    }
    else{
        for(int i=lans;i<=rans;i+=2)
        printf("%d ",i);
        printf("\n");
    }
}