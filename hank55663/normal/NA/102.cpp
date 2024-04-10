#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
typedef long long LL;/*
int main(){
    int a,b,c;
    int x,y,z;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
    if(a>x){
        printf("NO\n");
        return 0;
    }
    x-=a;
    int sum=x+y;
    if(b>sum){
        printf("NO\n");
        return 0;
    }
    sum-=b;
    sum+=c;
    if(c>sum){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}*/
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    pii p[200005];
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i);
    }
    sort(p+1,p+n+1);
    reverse(p+1,p+n+1);
    int vis[200005];
    MEM(vis);
    LL ans=0;
    for(int i=1;i<=m*k;i++){
        vis[p[i].y]=1;
        ans+=p[i].x;
    }
    printf("%lld\n",ans);
    int tot=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        tot+=vis[i];
        if(tot==m){
            cnt++;
            printf("%d ",i);
            tot=0;
        }
        if(cnt==k-1)
        break;
    }
    printf("\n");
}