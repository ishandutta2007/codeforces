//2018.9.16 by ljz
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
    namespace Trie{
        struct Trie{
            int son[2];
        }tr[N<<5];
        int cnt;
        inline void clean(const res &x){
            memset(tr[x].son,0,sizeof(tr[x].son));
        }
        void insert(res &x,const res &w,const res &p){
            if(!x)x=++cnt,clean(cnt);
            if(p==-1)return;
            insert(tr[x].son[(w>>p)&1],w,p-1);
        }
        int query(const res &x,const res &w,const res &p) {
            if(p==-1)return 0;
            res c=(w>>p)&1;
            return tr[x].son[c]?query(tr[x].son[c],w,p-1):query(tr[x].son[c^1],w,p-1)^(1<<p);
        }
    }
#define pb push_back
    int n;
    LL solve(vector<int> qaq,const res &p){
        if(!qaq.size()||p==-1)return 0;
        vector<int> vec[2];
        for(res i=0,siz=qaq.size();i<siz;i++)vec[(qaq[i]>>p)&1].pb(qaq[i]);
        res ret=0,rt;
        if(vec[0].size()&&vec[1].size()){
            ret=1<<(p+1);
            rt=0;
            Trie::cnt=0;
            for(res i=0,siz=vec[0].size();i<siz;i++)Trie::insert(rt,vec[0][i],30);
            for(res i=0,siz=vec[1].size();i<siz;i++)ret=_min(ret,Trie::query(rt,vec[1][i],30));
        }
        return ret+solve(vec[0],p-1)+solve(vec[1],p-1);
    }
    inline void MAIN(){
        n=read();
        vector<int> a;
        for(res i=1;i<=n;i++)a.pb(read());
        printf("%lld\n",solve(a,30));
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}