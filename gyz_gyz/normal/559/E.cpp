#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 200
using namespace std;
struct pr{int x,y;}a[mx];
int f[mx][mx],n,r,s,t,v,ans;
inline bool cmp(pr a,pr b){return a.x<b.x;}
int main(){
    scanf("%d",&n);a[0].x=-1000000000;
    rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    rep(i,1,n){
        rep(j,0,i-1){
            r=a[j].x+a[j].y;if(r>a[i].x)r=a[i].x;
            if(r<a[i-1].x)r=a[i-1].x;r-=a[i-1].x;
            s=j;if(a[i].x+a[i].y>a[j].x+a[j].y)s=i;
            if(f[i-1][j]+r>f[i][s])f[i][s]=f[i-1][j]+r;
        }t=0;
        dep(j,i-1,0){
            rep(k,0,j){
                s=a[k].x+a[k].y;if(s<a[j].x)s=a[j].x;if(s>a[i].x)s=a[i].x;
                r=a[i].x-a[i].y;if(r<s)r=s;r=a[i].x-r;s-=a[j].x;
                v=k;if(a[t].x+a[t].y>v)v=t;
                if(f[j][k]+r+s>f[i][v])f[i][v]=f[j][k]+r+s;
            }
            if(a[j].x+a[j].y>a[t].x+a[t].y)t=j;
        }
    }
    rep(i,0,n){
        s=a[i].x+a[i].y;if(s<a[n].x)s=a[n].x;s-=a[n].x;
        if(f[n][i]+s>ans)ans=f[n][i]+s;
    }
    printf("%d\n",ans);
}