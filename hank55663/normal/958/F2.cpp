#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    int tot=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int cnt[200005];
    int need[200005];
    for(int i=1;i<=m;i++)
        scanf("%d",&need[i]),tot+=need[i];
    MEM(cnt);
    int i=1,l=0,now=1;
    for(;i<=n;i++){
        cnt[a[i]]++;
        while(cnt[now]>=need[now])now++;
     //   printf("%d %d %d\n",now,cnt[now],need[now]);
       
        if(now>m)
        break;
    }
   // printf("%d",i);
    if(i==n+1)
    {
        printf("-1\n");
        return 0;
    }
    int ans=i-l-tot,last=1;
 //   printf("%d\n",ans);
    cnt[a[i]]--;
    last=a[i];
    for(;i<=n;i++){
        cnt[a[i]]++;
        while(need[last]<=cnt[last]){
            ans=min(ans,i-l-tot);
            l++;
            cnt[a[l]]--;
            last=a[l];
          //  printf("%d %d %d %d\n",i,ans,l-1,tot);
        }
       // printf("%d\n",l);
        
    }
    printf("%d\n",ans);
}