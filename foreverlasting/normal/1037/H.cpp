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
const int N=2e5+10;
namespace MAIN{
    struct SAM{
        struct Sam{
            int vis[26],par,len;
        }sam[N<<1];
        int cnt,las,rt;
        SAM() {cnt=las=rt=1;}
        inline void extend(const res &x){
            res p=las,np=++cnt;
            las=np,sam[np].len=sam[p].len+1;
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
    int n;
    char str[N];
    int sum[N<<6],ls[N<<6],rs[N<<6],rt[N<<1],tot;
    inline void pushup(const res &rt){
        sum[rt]=sum[ls[rt]]+sum[rs[rt]];
    }
    void update(res &rt,const res &l,const res &r,const res &p){
        if(!rt)rt=++tot;
        if(l==r){sum[rt]++;return;}
        res mid=(l+r)>>1;
        if(p<=mid)update(ls[rt],l,mid,p);
        else update(rs[rt],mid+1,r,p);
        pushup(rt);
    }
    int query(const res &rt,const res &l,const res &r,const res &L,const res &R){
        if(!rt)return 0;
        if(L<=l&&r<=R)return sum[rt];
        res mid=(l+r)>>1,ret=0;
        if(L<=mid)ret+=query(ls[rt],l,mid,L,R);
        if(R>mid)ret+=query(rs[rt],mid+1,r,L,R);
        return ret;
    }
    int merge(const res &x,const res &y,const res &l,const res &r){
        if(!x||!y)return x+y;
        if(l==r){sum[x]+=sum[y];return x;}
        res mid=(l+r)>>1,z=++tot;
        ls[z]=merge(ls[x],ls[y],l,mid);
        rs[z]=merge(rs[x],rs[y],mid+1,r);
        pushup(z);
        return z;
    }
    int buc[N<<1],rnk[N<<1];
    int Q;
    int pos[N<<1];
    inline void MAIN(){
        scanf("%s",str+1);
        Q=read();
        n=strlen(str+1);
        for(res i=1;i<=n;i++)A.extend(str[i]-'a'),update(rt[A.las],1,n,i);
        for(res i=1;i<=A.cnt;i++)buc[A.sam[i].len]++;
        for(res i=1;i<=A.cnt;i++)buc[i]+=buc[i-1];
        for(res i=1;i<=A.cnt;i++)rnk[buc[A.sam[i].len]--]=i;
        for(res i=A.cnt;i>1;i--)rt[A.sam[rnk[i]].par]=merge(rt[A.sam[rnk[i]].par],rt[rnk[i]],1,n);
        pos[0]=1;
        while(Q--){
            res l=read(),r=read();
            scanf("%s",str+1);
            res m=strlen(str+1),lim=m;
            for(res i=1,now=1;i<=m;i++){
                res x=str[i]-'a';
                if(A.sam[now].vis[x])now=A.sam[now].vis[x],pos[i]=now;
                else {lim=i-1;break;}
            }
            bool flag=0;
            for(res i=lim;~i;i--){
                if(flag)break;
                for(res j=(i<m?str[i+1]-'a'+1:0);j<26;j++)
                    if(query(rt[A.sam[pos[i]].vis[j]],1,n,l+i,r)){
                        for(res k=1;k<=i;k++)putchar(str[k]);
                        putchar(j+'a'),puts("");
                        flag=1;
                        break;
                    }
            }
            if(!flag)puts("-1");
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}