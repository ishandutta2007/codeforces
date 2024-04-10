//2018.11.23 by ljz
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
const int N=2e6+10;
const int kcz=51123987;
namespace MAIN{
    struct PAM{
        struct Pam{
            int fail,len,dep;
        }pam[N];
        struct E{
            int next,to,val;
            E() {}
            E(res next,res to,res val):next(next),to(to),val(val) {}
        }edge[N];
        int head[N],Cnt;
        inline void addedge(const res &u,const res &v,const res &w){
            edge[++Cnt]=E(head[u],v,w),head[u]=Cnt;
        }
        inline int get(const res &u,const res &w){
            for(res i=head[u];~i;i=edge[i].next)if(edge[i].val==w)return edge[i].to;
            return 0;
        }
        int cnt,las;
        PAM() {pam[0].fail=pam[1].fail=1,pam[cnt=1].len=-1,memset(head,-1,sizeof(head));}
        inline void extend(const res &x,const res &id,const char *str){
            res p=las;
            for(;str[id-pam[p].len-1]!=str[id];p=pam[p].fail);
            if(!get(p,x)){
                res np=++cnt,q=pam[p].fail;
                for(;str[id-pam[q].len-1]!=str[id];q=pam[q].fail);
                pam[np].len=pam[p].len+2,pam[np].fail=get(q,x),addedge(p,np,x),pam[np].dep=pam[pam[np].fail].dep+1;
            }
            las=get(p,x);
        }
    }A,B;
    int ans;
    inline void add(res &x,const res &y){
        x+=y;
        x>=kcz?x-=kcz:1;
    }
    char str[N];
    int f[N],g[N];
    int n;
    inline void MAIN(){
        n=read();
        scanf("%s",str+1);
        for(res i=1;i<=n;i++)A.extend(str[i]-'a',i,str),f[i]=A.pam[A.las].dep,add(ans,f[i]);
        ans=1LL*ans*(ans-1)/2%kcz;
        reverse(str+1,str+n+1);
        for(res i=1;i<=n;i++)B.extend(str[i]-'a',i,str),g[n-i+1]=B.pam[B.las].dep;
        for(res i=n;i;i--)add(g[i],g[i+1]);
        for(res i=1;i<=n;i++)add(ans,kcz-1LL*f[i]*g[i+1]%kcz);
        printf("%d\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}