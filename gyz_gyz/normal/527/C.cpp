#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
struct vv{
    int a;long long b;
    inline friend bool operator < (const vv &a,const vv &b){
        return a.a!=b.a?a.a<b.a:a.b<b.b;
    }
}g,gg,ve;
struct re{
    int a,b;
    inline friend bool operator < (const re &a,const re &b){
        return a.b!=b.b?a.b<b.b:a.a<b.a;
    }
}rw;
int w,h,n,x;char ch[10];
set<vv>r;set<vv>e;
set<re>z;set<re>c;
int main(){
    scanf("%d%d%d",&w,&h,&n);
    ve.a=0;ve.b=w;r.insert(ve);
    ve.a=0;ve.b=h;e.insert(ve);
    rw.a=0;rw.b=w;z.insert(rw);
    rw.a=0;rw.b=h;c.insert(rw);
    rep(i,1,n){
        scanf("%s",ch);scanf("%d",&x);
        if(ch[0]=='V'){
            ve.a=x;ve.b=300000;
            g=*(--r.lower_bound(ve));
            rw.a=g.a;rw.b=g.b;z.erase(rw);
            gg.a=rw.a;gg.b=rw.b;r.erase(gg);
            rw.b=x-g.a;z.insert(rw);
            gg.a=rw.a;gg.b=rw.b;r. insert(gg);
            rw.b=g.b+g.a-x;rw.a=x;z.insert(rw);
            gg.a=rw.a;gg.b=rw.b;r.insert(gg);
        }else{
            ve.a=x;ve.b=300000;
            g=*(--e.lower_bound(ve));
            rw.a=g.a;rw.b=g.b;c.erase(rw);
            gg.a=rw.a;gg.b=rw.b;e.erase(gg);
            rw.b=x-g.a;c.insert(rw);
            gg.a=rw.a;gg.b=rw.b;e.insert(gg);
            rw.b=g.b+g.a-x;rw.a=x;c.insert(rw);
            gg.a=rw.a;gg.b=rw.b;e.insert(gg);
        }           
        printf("%I64d\n",1ll*(*(--z.end())).b*(*(--c.end())).b);
    }
}