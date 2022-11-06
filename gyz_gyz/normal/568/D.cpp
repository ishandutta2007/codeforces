#include<cstdio>
#include<cstdlib>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
#define abs(x) ((x)>0?(x):-(x))
#define eq(x,y) (abs((x)-(y))<1e-6)
using namespace std;
double a[mx],b[mx],c[mx];int et[mx],tm[mx],n,m,s,nn;
inline bool ck(int x,int y,int z){
    double p1=0,p2=0,r1=0,r2=0;
    if(!b[x]&&!b[y])return 0;
    if(!b[x])p1=-c[x]/a[x],p2=(a[y]*p1+c[y])/b[y];
    if(!b[y])p1=-c[y]/a[y],p2=(a[x]*p1+c[x])/b[x];
    if(b[x]&&b[y]){
        double s1=a[x]/b[x]-a[y]/b[y];
        double s2=c[y]/b[y]-c[x]/b[x];
        if(!s1)return 0;
        p1=s2/s1;p2=(a[x]*p1+c[x])/b[x];
    }
    if(!b[x]&&!b[z])return 0;
    if(!b[x])r1=-c[x]/a[x],r2=(a[z]*r1+c[z])/b[z];
    if(!b[z])r1=-c[z]/a[z],r2=(a[x]*r1+c[x])/b[x];
    if(b[x]&&b[z]){
        double s1=a[x]/b[x]-a[z]/b[z];
        double s2=c[z]/b[z]-c[x]/b[x];
        if(!s1)return 0;
        r1=s2/s1;r2=(a[x]*p1+c[x])/b[x];
    }
    return (eq(p1,r1)&&eq(p2,r2));
}
inline bool pe(int x,int y){
    if(!b[x]&&!b[y])return 0;
    if(b[x]&&b[y]&&!(a[x]/b[x]-a[y]/b[y]))return 0;
    return 1;
}    
void work(int k){
    if(!n){
        printf("YES\n");printf("%d\n",m-k);return;
    }
    if(!k){
        printf("NO\n");exit(0);
    }    
    s=k*(k+1)+1;int r1=1,r2=-1,v=-1;if(s>n)s=n;
    rep(i,1,s-1)rep(j,i+1,s)if(pe(i,j)){
        int w=0;
        rep(t,1,s)if(t!=i&&t!=j)
            if(ck(i,j,t))w++;
        if(w>v)v=w,r1=i,r2=j;
    }nn=0;
    if(r2>0){rep(i,1,n)if(r1!=i&&r2!=i&&!ck(r1,r2,i))tm[++nn]=i;}
    else rep(i,2,n)tm[++nn]=i;
    r1=et[r1];if(r2>0)r2=et[r2];
    n=nn;rep(i,1,n){
        a[i]=a[tm[i]];b[i]=b[tm[i]];
        c[i]=c[tm[i]];et[i]=et[tm[i]];
    }
    work(k-1);
    printf("%d %d\n",r1,r2);
}   
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
    rep(i,1,n)et[i]=i;work(m);
}