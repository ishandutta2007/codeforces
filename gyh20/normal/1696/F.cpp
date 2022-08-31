#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int n,m,t,fa[10002],siz[10002],oo,A[102],B[102],tot,G[102][102];
char s[102][102][102];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
    x=root(x),y=root(y);
    if(x==y)return;
    fa[x]=y,siz[y]+=siz[x];
}
inline int pos(re int x,re int y){
    if(x==y)oo=1;
    if(x>y)swap(x,y);
    return (x-1)*n+y;
}
int main(){
    t=read();
    while(t--){
        n=read();oo=0;
        for(re int i=1;i<=n*n;++i)fa[i]=i,siz[i]=1;
        for(re int i=1;i<=n;++i)
            for(re int j=i+1;j<=n;++j)
                scanf("%s",s[i][j]+1);
        for(re int i=1;i<=n;++i)
            for(re int j=i+1;j<=n;++j)
                for(re int k=1;k<=n;++k)
                    if(s[i][j][k]=='1')
                        Merge(pos(i,k),pos(j,k));
        if(oo){
            puts("No");
            continue;
        }
        re bool ia=1;
        for(re int i=1;i<=n*n&&ia;++i)
            if(i==root(i)&&siz[i]==n-1&&i!=1){
                tot=0;
                for(re int j=1;j<=n*n;++j)
                    if(root(j)==i)
                        A[++tot]=(j-1)/n+1,B[tot]=(j-1)%n+1;
                for(re int j=1;j<=n;++j)
                    for(re int k=1;k<=n;++k)
                        G[j][k]=114514;
                for(re int j=1;j<=n;++j)G[j][j]=0;
                for(re int j=1;j<=tot;++j)G[A[j]][B[j]]=G[B[j]][A[j]]=1;
                for(re int j=1;j<=n;++j)
                    for(re int k=1;k<=n;++k)
                        for(re int l=1;l<=n;++l)
                            G[k][l]=min(G[k][l],G[k][j]+G[j][l]);
                re bool oo=1;
                for(re int j=1;j<=n;++j)
                    for(re int k=1;k<=n;++k)
                        oo&=G[j][k]<=n;
                for(re int j=1;j<=n;++j)
                    for(re int k=j+1;k<=n;++k)
                        for(re int l=1;l<=n;++l)
                            oo&=(G[j][l]==G[k][l])==(s[j][k][l]=='1');
                if(oo){
                    ia=0;
                    puts("Yes");
                    for(re int j=1;j<=tot;++j)printf("%d %d\n",A[j],B[j]);
                }
            }
        if(ia)puts("No");

    }
}