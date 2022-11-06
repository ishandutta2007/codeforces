#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 2097152
using namespace std;
struct pr{int x,y;}b[mx];
int a[mx],l[mx],r[mx],lz[mx],nu[mx],s1[mx],p1[mx],s2[mx],p2[mx],n,t1,t2,j;long long ans;
inline bool cmp(pr a,pr b){return a.x<b.x;}
int fd(int w,int L,int R,int x){
    if(x*2<mx){lz[x*2]+=lz[x];lz[x*2+1]+=lz[x];}
    a[x]+=lz[x];lz[x]=0;
    if(L==l[x]&&R==r[x])if(a[x]>w)return 0;else return nu[x];
    if(R<=r[x*2])return fd(w,L,R,x*2);
    if(L>=l[x*2+1])return fd(w,L,R,x*2+1);
    return fd(w,L,r[x*2],x*2)+fd(w,l[x*2+1],R,x*2+1);
}   
void add(int w,int L,int R,int x){
    if(L==l[x]&&R==r[x]){lz[x]+=w;return;}
    if(R<=r[x*2])add(w,L,R,x*2);
    else if(L>=l[x*2+1])add(w,L,R,x*2+1);
    else {add(w,L,r[x*2],x*2);add(w,l[x*2+1],R,x*2+1);}
    int a1=a[x*2]+lz[x*2],a2=a[x*2+1]+lz[x*2+1];
    if(a1<a2){a[x]=a1;nu[x]=nu[x*2];}
    if(a1>a2){a[x]=a2;nu[x]=nu[x*2+1];}
    if(a1==a2){a[x]=a1;nu[x]=nu[x*2]+nu[x*2+1];}
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&b[i].x,&b[i].y);
    sort(b+1,b+n+1,cmp);
    l[1]=1;r[1]=mx/2;
    rep(i,1,mx/2-1){
        l[i*2]=l[i];r[i*2]=(l[i]+r[i])/2;
        l[i*2+1]=r[i*2]+1;r[i*2+1]=r[i];
    }
    rep(i,1,mx-1)nu[i]=r[i]-l[i]+1;
    rep(i,1,mx/2)add(i,i,i,1);
    rep(i,1,n){
        for(j=i;t1&&s1[t1]<b[i].y;t1--){
            add(b[i].y-s1[t1],p1[t1],j-1,1);j=p1[t1];
        }
        p1[++t1]=j;s1[t1]=b[i].y;
        for(j=i;t2&&s2[t2]>b[i].y;t2--){
            add(s2[t2]-b[i].y,p2[t2],j-1,1);j=p2[t2];
        }
        p2[++t2]=j;s2[t2]=b[i].y;ans+=fd(i,1,i,1);
    }
    printf("%I64d\n",ans);
}