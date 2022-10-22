//2018.11.21 by ljz
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
const int N=3e5+10;
namespace MAIN{
    char str[N];
    int Q;
    struct AC{
        struct Ac{
            int vis[26],fail,num,tot,son[26];
        }ac[N];
        int rt[N],top,cnt,siz[N];
        int merge(const res &x,const res &y){
            if(!x||!y)return x+y;
            ac[x].tot+=ac[y].tot;
            for(res i=0;i<26;i++)ac[x].son[i]=merge(ac[x].son[i],ac[y].son[i]);
            return x;
        }
        int q[N*26],he,ta;
        inline void get_fail(const res &rt){
            he=1,ta=0;
            for(res i=0;i<26;i++){
                if(ac[rt].son[i])ac[ac[rt].vis[i]=ac[rt].son[i]].fail=rt,q[++ta]=ac[rt].vis[i];
                else ac[rt].vis[i]=rt;
            }
            while(he<=ta){
                res u=q[he++];
                for(res i=0;i<26;i++){
                    if(ac[u].son[i])ac[ac[u].vis[i]=ac[u].son[i]].fail=ac[ac[u].fail].vis[i],q[++ta]=ac[u].vis[i];
                    else ac[u].vis[i]=ac[ac[u].fail].vis[i];
                }
                ac[u].num=ac[u].tot+ac[ac[u].fail].num;
            }
        }
        inline void insert(const char *str){
            rt[++top]=++cnt,siz[top]=1;
            res now=rt[top];
            for(res i=0,len=strlen(str);i<len;i++){
                res x=str[i]-'a';
                if(!ac[now].son[x])ac[now].son[x]=++cnt,now=cnt;
                else now=ac[now].son[x];
            }
            ac[now].tot=1;
            while(siz[top]==siz[top-1])top--,rt[top]=merge(rt[top],rt[top+1]),siz[top]+=siz[top+1];
            get_fail(rt[top]);
        }
        inline int query(const char *str){
            res ret=0,len=strlen(str);
            for(res i=1;i<=top;i++)
                for(res j=0,now=rt[i];j<len;j++)now=ac[now].vis[str[j]-'a'],ret+=ac[now].num;
            return ret;
        }
    }A,B;
    inline void MAIN(){
        Q=read();
        while(Q--){
            res opt=read();
            scanf("%s",str);
            if(opt==1)A.insert(str);
            if(opt==2)B.insert(str);
            if(opt==3)printf("%d\n",A.query(str)-B.query(str)),fflush(stdout);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}