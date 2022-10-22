//2018.10.28 by ljz
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
namespace MAIN{
    int n;
    struct Treap{
        int son[2],va,pri,siz,laz;
    }tr[N];
    int dp[N];
    int st[N],top,tot;
    int rt;
    inline void pushup(const res &x){
        tr[x].siz=tr[tr[x].son[0]].siz+tr[tr[x].son[1]].siz+1;
    }
    inline int newnode(const res &va){
        res cnt;
        if(top)cnt=st[top--];
        else cnt=++tot;
        tr[cnt].va=va,tr[cnt].son[0]=tr[cnt].son[1]=tr[cnt].laz=0,tr[cnt].siz=1,tr[cnt].pri=rand();
        return cnt;
    }
    inline void change(const res &x,const res &va){
        if(!x)return;
        tr[x].laz+=va,tr[x].va+=va;
    }
    inline void pushdown(const res &x){
        if(!x||!tr[x].laz)return;
        change(tr[x].son[0],tr[x].laz),change(tr[x].son[1],tr[x].laz);
        tr[x].laz=0;
    }
    int merge(const res &x,const res &y){
        if(!x||!y)return x+y;
        pushdown(x),pushdown(y);
        if(tr[x].pri<tr[y].pri){
            tr[x].son[1]=merge(tr[x].son[1],y);
            pushup(x);
            return x;
        }
        else {
            tr[y].son[0]=merge(x,tr[y].son[0]);
            pushup(y);
            return y;
        }
    }
    void split(res now,res k,res &x,res &y){
        if(!now){x=y=0;return;}
        pushdown(now);
        if(tr[now].va<=k)x=now,split(tr[now].son[1],k,tr[now].son[1],y);
        else y=now,split(tr[now].son[0],k,x,tr[now].son[0]);
        pushup(now);
    }
    inline int kth(res now,res k){
        if(!k)return 0;
        while(233){
            if(tr[tr[now].son[0]].siz==k-1)return now;
            if(tr[tr[now].son[0]].siz>=k)now=tr[now].son[0];
            else k-=tr[tr[now].son[0]].siz+1,now=tr[now].son[1];
        }
    }
    inline int pre(const res &va){
        res a,b,ret;
        split(rt,va-1,a,b),ret=kth(a,tr[a].siz),rt=merge(a,b);
        return ret;
    }
    inline int nxt(const res &va){
        res a,b,ret;
        split(rt,va,a,b),ret=kth(b,1),rt=merge(a,b);
        return ret;
    }
    inline void insert(const res &va){
        res a,b;
        split(rt,va,a,b),rt=merge(merge(a,newnode(va)),b);
    }
    inline void del(const res &va){
        res a,b,c,d;
        split(rt,va,a,b),split(a,va-1,c,d),st[++top]=d,d=merge(tr[d].son[0],tr[d].son[1]),rt=merge(merge(c,d),b);
    }
    inline void modify(const res &l,const res &r){
    	res a,b,c,d;
    	split(rt,l-1,a,b),split(b,r,c,d),change(c,1),rt=merge(a,merge(c,d));
	}
	void Dfs(res x){
		if(!x)return;
		pushdown(x);
		Dfs(tr[x].son[0]),printf("%d\n",tr[x].va),Dfs(tr[x].son[1]);
	}
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++){
            res l=read(),r=read();
            if(i==1){insert(l);continue;}
            res p=pre(l),q=nxt(r-1);
//            printf("%d %d %d\n",p,q,rt);
//            Dfs(rt);
            modify(l,r-1);
            if(q)del(tr[q].va);
            insert(l);
        }
        if(!rt)puts("0");
        else printf("%d\n",tr[rt].siz);
    }
}
int main(){
    srand((unsigned)time(NULL));
    MAIN::MAIN();
    return 0;
}