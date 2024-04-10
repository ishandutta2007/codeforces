#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 1000000
pii val[250005];
int f[250005];
int vis[250005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
pii p[250005];
int go[250005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[250005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        p[i]=mp(a[i],i);
    }
    sort(p,p+n);
    for(int i = 0;i<n;i++)f[i]=i,val[i]=mp(a[i],i),vis[i]=0,go[i]=0;
    for(int i = 0;i<n;i++){
        int x=p[i].y;
        if(x!=n-1&&vis[x+1]){
            go[x]=val[Find(x+1)].y;
            pii p=val[Find(x)];
            f[Find(x)]=Find(x+1);
            val[Find(x+1)]=min(p,val[Find(x+1)]);
        }
        if(x!=0&&vis[x-1]){
            pii p=val[Find(x-1)];
            f[Find(x-1)]=Find(x);
            val[Find(x)]=min(p,val[Find(x)]);
        }
        vis[x]=1;
    }
       // for(int i = 0;i<n;i++)printf("%d ",go[i]);
   // printf("\n");
    reverse(p,p+n);
    for(int i = 0;i<n;i++)f[i]=i,val[i]=mp(a[i],i),vis[i]=0;
    for(int i = 0;i<n;i++){
        int x=p[i].y;
        if(x!=n-1&&vis[x+1]){
            go[x]=val[Find(x+1)].y;
            pii p=val[Find(x)];
            f[Find(x)]=Find(x+1);
            val[Find(x+1)]=max(p,val[Find(x+1)]);
        }
        if(x!=0&&vis[x-1]){
            pii p=val[Find(x-1)];
            f[Find(x-1)]=Find(x);
            val[Find(x)]=max(p,val[Find(x)]);
        }
        vis[x]=1;
    }
    //for(int i = 0;i<n;i++)printf("%d ",go[i]);
   // printf("\n");
    int now=0,ans=0;
    while(now!=n-1){
        now=go[now];
        ans++;
   //     printf("%d\n",now);
      //  getchar();
    }
    printf("%d\n",ans);
}
int main(){
 //   srand(time(NULL));
    int t=1;00000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}