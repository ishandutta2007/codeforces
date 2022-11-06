#include<cstdio>
#include<algorithm>
#define N 100001
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
struct pr{int x,y,id;}a[N];
inline bool cmp(pr x,pr y){
    if(x.x!=y.x)return x.x<y.x;
    if(x.y!=y.y)return x.y>y.y;
    return x.id<y.id;
}
int n,m,tot,s,v,f[N],t[N];
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m)scanf("%d%d",&a[i].x,&a[i].y);
    rep(i,1,m)a[i].id=i;
    sort(a+1,a+m+1,cmp);tot=1;s=0;v=2;
    rep(i,1,m){
        if(a[i].y==1){
            f[a[i].id]=tot;t[a[i].id]=++tot;
        }else{
            s++;if(s==v-1)v++,s=1;
            if(v>tot){printf("-1\n");return 0;}
            f[a[i].id]=s;t[a[i].id]=v;
        }
    }
    rep(i,1,m)printf("%d %d\n",f[i],t[i]);
}