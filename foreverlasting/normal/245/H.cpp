//2018.11.22 by ljz
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
const int N=5e3+10;
namespace MAIN{
    struct PAM{
        struct Pam{
            int vis[26],fail,len,dep;
            inline void init(){
                memset(vis,0,sizeof(vis));
                fail=len=dep=0;
            }
        }pam[N];
        int cnt,las;
        inline void INIT(){
            las=0;
            pam[0].init(),pam[1].init();
            pam[0].fail=pam[1].fail=1,pam[cnt=1].len=-1;
        }
        inline void extend(const res &x,const res &id,const char *str){
            res p=las;
            for(;str[id-pam[p].len-1]!=str[id];p=pam[p].fail);
            if(!pam[p].vis[x]){
                res np=++cnt,q=pam[p].fail;
                pam[np].init();
                for(;str[id-pam[q].len-1]!=str[id];q=pam[q].fail);
                pam[np].len=pam[p].len+2,pam[np].fail=pam[q].vis[x],pam[p].vis[x]=np,pam[np].dep=pam[pam[q].vis[x]].dep+1;
            }
            las=pam[p].vis[x];
        }
    }A;
    char str[N],S[N];
    int Q;
    int cnt[N][N];
    inline void MAIN(){
        scanf("%s",str+1);
        for(res i=1,n=strlen(str+1);i<=n;i++){
            A.INIT();
            for(res j=i;j<=n;j++)S[j-i+1]=str[j];
            for(res j=i;j<=n;j++)A.extend(str[j]-'a',j-i+1,S),cnt[i][j]=cnt[i][j-1]+A.pam[A.las].dep;
        }
        Q=read();
        while(Q--){
            res l=read(),r=read();
            printf("%d\n",cnt[l][r]);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}