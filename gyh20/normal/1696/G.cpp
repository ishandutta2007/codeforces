#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
double T[800002][5][5],val[5],CUR[5],NW[5];
int n,m,X,Y,a[200002];
inline void build(re int p,re int l,re int r){
    for(re int i=0;i<3;++i)for(re int j=0;j<3;++j)T[p][i][j]=-1e18;
    if(l==r){
        for(re int i=0;i<3;++i)T[p][i][i]=val[i]*a[l];
        return;
    }
    re int mid=l+r>>1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    for(re int i=0;i<3;++i)
        for(re int j=0;j<3;++j)
            for(re int k=0;k<3;++k)
                for(re int l=0;l<3;++l)
                    if(val[j]*X+val[k]*Y<1+1e-9&&val[k]*X+val[j]*Y<1+1e-9)
                        T[p][i][l]=max(T[p][i][l],T[p<<1][i][j]+T[p<<1|1][k][l]);
}
inline void cg(re int p,re int l,re int r,re int x){
    for(re int i=0;i<3;++i)for(re int j=0;j<3;++j)T[p][i][j]=-1e18;
    if(l==r){
        for(re int i=0;i<3;++i)T[p][i][i]=val[i]*a[l];
        return;
    }
    re int mid=l+r>>1;
    if(x<=mid)cg(p<<1,l,mid,x);
    else cg(p<<1|1,mid+1,r,x);
    for(re int i=0;i<3;++i)
        for(re int j=0;j<3;++j)
            for(re int k=0;k<3;++k)
                for(re int l=0;l<3;++l)
                    if(val[j]*X+val[k]*Y<1+1e-9&&val[k]*X+val[j]*Y<1+1e-9)
                        T[p][i][l]=max(T[p][i][l],T[p<<1][i][j]+T[p<<1|1][k][l]);
}
inline void ask(re int p,re int l,re int r,re int x,re int y){
    if(l>=x&&r<=y){
        for(re int i=0;i<3;++i)NW[i]=0;
        for(re int i=0;i<3;++i)
            for(re int j=0;j<3;++j)
                for(re int k=0;k<3;++k)
                    if(val[i]*X+val[j]*Y<1+1e-9&&val[i]*Y+val[j]*X<1+1e-9)
                        NW[k]=max(NW[k],CUR[i]+T[p][j][k]);
        for(re int i=0;i<3;++i)CUR[i]=NW[i];
        return;
    }
    re int mid=l+r>>1;
    if(x<=mid)ask(p<<1,l,mid,x,y);
    if(y>mid)ask(p<<1|1,mid+1,r,x,y);
}
int main(){
    n=read(),m=read(),X=read(),Y=read();if(X<Y)swap(X,Y);
    val[1]=1.0/(X+Y),val[2]=1.0/X;
    for(re int i=1;i<=n;++i)a[i]=read();
    build(1,1,n);
    while(m--){
        re int o=read(),x=read(),y=read();
        if(o==1)a[x]=y,cg(1,1,n,x);
        else{
            for(re int i=0;i<3;++i)CUR[i]=0;
            ask(1,1,n,x,y);
            double ans=0;
            for(re int i=0;i<3;++i)ans=max(ans,CUR[i]);
            printf("%.10lf\n",ans);
        }
    }
}