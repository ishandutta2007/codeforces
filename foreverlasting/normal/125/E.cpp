//2018.9.14 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int M=1e5+10;
const int N=5e3+10;
namespace MAIN{
    int n,m,k;
    struct E{
        int u,v,w,id;
        E() {}
        E(res u,res v,res w,res id):u(u),v(v),w(w),id(id) {}
        inline bool operator < (const E &b) const {
            return w!=b.w?w<b.w:u>b.u;
        }
    }edge[M],ed0[M];
    int fa[N];
    inline int find(res x){
        while(x!=fa[x])x=fa[x]=fa[fa[x]];
        return x;
    }
    int cnt;
    int ED[M],sum;
    inline void init(res lim){
        for(res i=1;i<=n;i++)fa[i]=i;
        cnt=sum=0;
        for(res i=1;i<=m;i++){
            res u=edge[i].u,v=edge[i].v,w=u==1?edge[i].w+lim:edge[i].w;
            ed0[i]=E(u,v,w,i);
        }
        sort(ed0+1,ed0+1+m);
    }
    inline void calc(res lim){
        init(lim);
        for(res i=1;i<=m;i++){
            res u=ed0[i].u,v=ed0[i].v,fu=find(u),fv=find(v);
            if(fu==fv||(u==1&&cnt==k))continue;
            fa[fu]=fv;
            ED[++sum]=ed0[i].id;
            if(u==1)cnt++;
            if(sum==n-1)break;
        }
    }
    inline void MAIN(){
        n=read(),m=read(),k=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read(),w=read();
            if(u>v)_swap(u,v);
            edge[i]=E(u,v,w,i);
        }
        res l=-m,r=m;
        while(l<r){
            res mid=(l+r+1)>>1;
            calc(mid);
            if(cnt>=k)l=mid;
            else r=mid-1;
        }
        calc(l);
        if(sum!=n-1||cnt<k)puts("-1");
        else {
            printf("%d\n",sum);
            for(res i=1;i<=sum;i++)printf("%d ",ED[i]);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}