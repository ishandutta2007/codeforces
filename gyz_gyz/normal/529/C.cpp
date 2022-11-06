#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 262144
using namespace std;
struct pr{int x,y;}c[mx];
struct qq{int x1,y1,x2,y2,id;}qs[mx];
int a[mx],l[mx],r[mx],ans[mx],n,m,k,q,j,s;
inline bool prcmp1(pr x,pr y){return x.x<y.x;}
inline bool qqcmp1(qq x,qq y){return x.x2<y.x2;}
inline bool prcmp2(pr x,pr y){return x.y<y.y;}
inline bool qqcmp2(qq x,qq y){return x.y2<y.y2;}
void cg(int x,int y,int s){
    if(l[s]==r[s]){a[s]=y;return;}
    if(x<=r[s*2])cg(x,y,s*2);else cg(x,y,s*2+1);
    if(a[s*2]<a[s*2+1])a[s]=a[s*2];else a[s]=a[s*2+1];
}
int f(int L,int R,int s){
    if(l[s]==L&&r[s]==R)return a[s];
    if(R<=r[s*2])return f(L,R,s*2);
    if(L>=l[s*2+1])return f(L,R,s*2+1);
    int s1=f(L,r[s*2],s*2);
    int s2=f(l[s*2+1],R,s*2+1);
    if(s1<s2)return s1;else return s2;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&q);
    rep(i,1,k)scanf("%d%d",&c[i].x,&c[i].y);
    rep(i,1,q)scanf("%d%d%d%d",&qs[i].x1,&qs[i].y1,&qs[i].x2,&qs[i].y2);
    rep(i,1,q)qs[i].id=i;l[1]=1;r[1]=mx/2;
    rep(i,1,mx/2-1){
        l[i*2]=l[i];r[i*2]=(l[i]+r[i])/2;
        l[i*2+1]=r[i*2]+1;r[i*2+1]=r[i];
    }
    sort(c+1,c+k+1,prcmp1);sort(qs+1,qs+q+1,qqcmp1);j=1;s=1;
    rep(i,1,n){
        for(;j<=k&&c[j].x<=i;j++)cg(c[j].y,c[j].x,1);
        for(;s<=q&&qs[s].x2<=i;s++)if(f(qs[s].y1,qs[s].y2,1)>=qs[s].x1)ans[qs[s].id]=1;
    }
    rep(i,1,n)cg(i,0,1);
    sort(c+1,c+k+1,prcmp2);sort(qs+1,qs+q+1,qqcmp2);j=1;s=1;
    rep(i,1,m){
        for(;j<=k&&c[j].y<=i;j++)cg(c[j].x,c[j].y,1);
        for(;s<=q&&qs[s].y2<=i;s++)if(f(qs[s].x1,qs[s].x2,1)>=qs[s].y1)ans[qs[s].id]=1;
    }
    rep(i,1,q)if(ans[i])printf("YES\n");else printf("NO\n");
}