//2018.9.13 by ljz
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
const int N=1.1e5+10,NN=320;
namespace MAIN{
    int n,m;
    int a[N],len,part[N];
    struct P{
        int rt,num;
        bool p;
    }va[NN][N];
    inline void clear(P &x){
        x.rt=x.num=x.p=0;
    }
    int fa[N];
    inline int find(res x){
        while(x!=fa[x])x=fa[x]=fa[fa[x]];
        return x;
    }
    int Max[NN],laz[NN],pos[N];
    inline void pre(const res &blo){
        Max[blo]=0;
        for(res i=(blo-1)*len+1;i<=blo*len;i++){
            Max[blo]=_max(Max[blo],a[i]);
            if(va[blo][a[i]].p)fa[i]=va[blo][a[i]].rt;
            else pos[i]=a[i],va[blo][a[i]].p=1,fa[i]=i,va[blo][a[i]].rt=i;
            va[blo][a[i]].num++;
        }
    }
    inline void del(const res &blo){
        for(res i=(blo-1)*len+1;i<=blo*len;i++)a[i]=pos[find(i)],clear(va[blo][a[i]]),a[i]-=laz[blo];
        for(res i=(blo-1)*len+1;i<=blo*len;i++)fa[i]=0;
        laz[blo]=0;
    }
    inline void MOD(const res &blo,const res &a,const res &b){
        if(va[blo][b].p)fa[va[blo][a].rt]=va[blo][b].rt;
        else va[blo][b].p=1,va[blo][b].rt=va[blo][a].rt,pos[va[blo][a].rt]=b;
        va[blo][b].num+=va[blo][a].num,clear(va[blo][a]);
    }
    inline void change(const res &blo,const res &x){
        if(Max[blo]-laz[blo]>=x*2){
            for(res i=laz[blo]+1;i<=laz[blo]+x;i++)if(va[blo][i].p)MOD(blo,i,i+x);
            laz[blo]+=x;
        }
        else {
            for(res i=laz[blo]+x+1;i<=Max[blo];i++)if(va[blo][i].p)MOD(blo,i,i-x);
            Max[blo]=_min(Max[blo],laz[blo]+x);
        }
    }
    inline void modify(const res &l,const res &r,const res &x){
        res pl=part[l],pr=part[r];
        if(pl!=pr){
            del(pl),del(pr);
            for(res i=l;i<=pl*len;i++)if(a[i]>x)a[i]-=x;
            for(res i=(pr-1)*len+1;i<=r;i++)if(a[i]>x)a[i]-=x;
            for(res i=pl+1;i<pr;i++)change(i,x);
            pre(pl),pre(pr);
        }
        else {
            del(pl);
            for(res i=l;i<=r;i++)if(a[i]>x)a[i]-=x;
            pre(pl);
        }
    }
    inline int query(const res &l,const res &r,const res &x){
        res pl=part[l],pr=part[r],ans=0;
        if(pl!=pr){
            for(res i=l;i<=pl*len;i++)if(pos[find(i)]==x+laz[pl])ans++;
            for(res i=(pr-1)*len+1;i<=r;i++)if(pos[find(i)]==x+laz[pr])ans++;
            for(res i=pl+1;i<pr;i++)if(x+laz[i]<N)ans+=va[i][x+laz[i]].num;
        }
        else {
            for(res i=l;i<=r;i++)if(pos[find(i)]==x+laz[pl])ans++;
        }
        return ans;
    }
    inline void MAIN(){
        n=read(),m=read();
        len=sqrt(n);
        for(res i=1;i<=n;i++)a[i]=read(),part[i]=(i-1)/len+1;
        for(res i=1;i<=part[n];i++)pre(i);
        while(m--){
            res opt=read(),l=read(),r=read(),x=read();
            if(opt==1)modify(l,r,x);
            if(opt==2)printf("%d\n",query(l,r,x));
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}