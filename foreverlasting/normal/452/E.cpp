//2018.11.16 by ljz
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
const int N=3e5+10;
const int kcz=1e9+7;
namespace MAIN{
    int sz[N<<1][3];
    struct SAM{
        struct Sam{
            int vis[26],par,len;
        }sam[N<<1];
        int cnt,las,rt;
        SAM() {cnt=las=rt=1;}
        inline void extend(const res &x,const res &id){
            res p=las,np=++cnt;
            las=np,sam[np].len=sam[p].len+1,sz[np][id]++;
            for(;p&&!sam[p].vis[x];p=sam[p].par)sam[p].vis[x]=np;
            if(!p)sam[np].par=rt;
            else {
                res q=sam[p].vis[x];
                if(sam[q].len==sam[p].len+1)sam[np].par=q;
                else {
                    res nq=++cnt;
                    memcpy(sam[nq].vis,sam[q].vis,sizeof(sam[nq].vis));
                    sam[nq].len=sam[p].len+1,sam[nq].par=sam[q].par,sam[q].par=sam[np].par=nq;
                    for(;p&&sam[p].vis[x]==q;p=sam[p].par)sam[p].vis[x]=nq;
                }
            }
        }
    }A;
    char str[N];
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int head[N<<1],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
    }
    int ans[N];
    inline void add(res &x,const res &y){
        x+=y;
        x>=kcz?x-=kcz:1;
    }
    void dfs(const res &x){
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            dfs(tox);
            sz[x][0]+=sz[tox][0],sz[x][1]+=sz[tox][1],sz[x][2]+=sz[tox][2];
        }
        add(ans[A.sam[A.sam[x].par].len+1],1LL*sz[x][0]*sz[x][1]%kcz*sz[x][2]%kcz);
        add(ans[A.sam[x].len+1],kcz-1LL*sz[x][0]*sz[x][1]%kcz*sz[x][2]%kcz);
    }
    int mi=inf;
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        scanf("%s",str+1),A.las=1;
        mi=_min(mi,strlen(str+1));
        for(res i=1,sz=strlen(str+1);i<=sz;i++)A.extend(str[i]-'a',0);
        scanf("%s",str+1),A.las=1;
        mi=_min(mi,strlen(str+1));
        for(res i=1,sz=strlen(str+1);i<=sz;i++)A.extend(str[i]-'a',1);
        scanf("%s",str+1),A.las=1;
        mi=_min(mi,strlen(str+1));
        for(res i=1,sz=strlen(str+1);i<=sz;i++)A.extend(str[i]-'a',2);
        for(res i=2;i<=A.cnt;i++)if(A.sam[i].par)addedge(A.sam[i].par,i);
        dfs(1);
        for(res i=1;i<=mi;i++)add(ans[i],ans[i-1]),printf("%d ",ans[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}