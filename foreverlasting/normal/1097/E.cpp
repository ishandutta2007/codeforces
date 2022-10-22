//2019.3.20 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN {
    int T;
    int n,a[N];
    vector<int> ans[N];
    int ansx;
#define pb push_back
    int st[N],top;
    int head[N],nxt[N],pre[N];
    inline int LIS(){
        for(res i=1;i<=top;i++)head[i]=nxt[i]=pre[i]=0;
        st[top=1]=N;
        for(res i=1;i<=n;i++){
            res p=int(upper_bound(st+1,st+top+1,a[i])-st);
            st[p]=a[i],pre[i]=head[p],head[p]=i,nxt[i]=head[p-1];
            if(p==top)st[++top]=N;
        }
        return top-1;
    }
    inline void find(const res &x){
        ans[++ansx].clear();
        for(res i=head[x];i;i=nxt[i])ans[ansx].pb(a[i]),a[i]=-1;
    }
    inline void div(const res &n){
        for(res x=1;x<=n;x++){
            ans[++ansx].clear();
            for(res i=head[x];i;i=pre[i])ans[ansx].pb(a[i]);
        }
    }
    inline void MAIN(){
        T=read();
        while(T--){
            n=read(),ansx=0;
            for(res i=1;i<=n;i++)a[i]=read();
            while(n){
                res k=LIS();
                if(1LL*k*(k+1)/2>n)find(k);
                else {div(k);break;}
                res tot=0;
                for(res i=1;i<=n;i++)
                    if(a[i]!=-1)a[++tot]=a[i];
                n=tot;
            }
            printf("%d\n",ansx);
            for(res i=1;i<=ansx;i++){
                res sz=int(ans[i].size());
                printf("%d ",sz);
                for(res j=sz-1;~j;j--)printf("%d ",ans[i][j]);
                puts("");
            }
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}