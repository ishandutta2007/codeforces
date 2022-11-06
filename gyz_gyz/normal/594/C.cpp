#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define ll unsigned long long
#define N 200000
using namespace std;
int n,k,x1,y1,x2,y2,v[N];ll ans;
struct pr{int x,id;}x[N],y[N];
inline bool cmp(pr x,pr y){return x.x<y.x;}
int main(){
    scanf("%d%d",&n,&k);
    ans=4000000000ll;ans=ans*ans;
    rep(i,1,n){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x[i].x=x1+x2;y[i].x=y1+y2;
        x[i].id=i;y[i].id=i;
    }   
    sort(x+1,x+n+1,cmp);sort(y+1,y+n+1,cmp);
    rep(i1,0,k)
        rep(i2,0,k-i1)
            rep(i3,0,k-i1-i2)
                rep(i4,0,k-i1-i2-i3){
                    int j1=1;while(v[x[j1].id])j1++;
                    rep(j,1,i1){
                        v[x[j1].id]=1;j1++;
                        while(v[x[j1].id])j1++;
                    }
                    int j2=1;while(v[y[j2].id])j2++;
                    rep(j,1,i2){
                        v[y[j2].id]=1;j2++;
                        while(v[y[j2].id])j2++;
                    }
                    int j3=n;while(v[x[j3].id])j3--;
                    rep(j,1,i3){
                        v[x[j3].id]=1;j3--;
                        while(v[x[j3].id])j3--;
                    }
                    int j4=n;while(v[y[j4].id])j4--;
                    rep(j,1,i4){
                        v[y[j4].id]=1;j4--;
                        while(v[y[j4].id])j4--;
                    }
                    int l1=x[j3].x-x[j1].x;
                    int l2=y[j4].x-y[j2].x;
                    if(!l1)l1=2;if(!l2)l2=2;
                    if(l1&1)l1++;if(l2&1)l2++;
                    if(1ll*l1*l2<ans)ans=1ll*l1*l2;
                    rep(j,1,j1)v[x[j].id]=0;
                    rep(j,1,j2)v[y[j].id]=0;
                    rep(j,j3,n)v[x[j].id]=0;
                    rep(j,j4,n)v[y[j].id]=0;                    
                }
    printf("%I64d\n",ans/4);
}