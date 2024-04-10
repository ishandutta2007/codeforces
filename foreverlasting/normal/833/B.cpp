//2018.. by ljz
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
const int N=35000+10;
namespace MAIN{
	int n,k;
	int dp[N];
	int sum[N<<2],tag[N<<2];
	inline void pushup(const res &rt){
		sum[rt]=_max(sum[rt<<1],sum[rt<<1|1]);
	}
	void build(const res &rt,const res &l,const res &r){
		tag[rt]=sum[rt]=0;
		if(l==r){sum[rt]=dp[l-1];return;}
		res mid=(l+r)>>1;
		build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	inline void change(const res &rt,const res &va){
		tag[rt]+=va,sum[rt]+=va;
	}
	inline void pushdown(const res &rt){
		if(!tag[rt])return;
		change(rt<<1,tag[rt]),change(rt<<1|1,tag[rt]);
		tag[rt]=0;
	}
	void modify(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va){
		if(L>R)return;
		if(L<=l&&r<=R){change(rt,va);return;}
		pushdown(rt);
		res mid=(l+r)>>1;
		if(L<=mid)modify(rt<<1,l,mid,L,R,va);
		if(R>mid)modify(rt<<1|1,mid+1,r,L,R,va);
		pushup(rt);
	}
	int query(const res &rt,const res &l,const res &r,const res &L,const res &R){
		if(L>R)return 0;
		if(L<=l&&r<=R)return sum[rt];
		pushdown(rt);
		res mid=(l+r)>>1,ret=0;
		if(L<=mid)ret=_max(ret,query(rt<<1,l,mid,L,R));
		if(R>mid)ret=_max(ret,query(rt<<1|1,mid+1,r,L,R));
		return ret;
	}
	int a[N],pre[N],pos[N];
	inline void MAIN(){
		n=read(),k=read();
		for(res i=1;i<=n;i++)a[i]=read(),pre[i]=pos[a[i]],pos[a[i]]=i;
		for(res i=1;i<=k;i++){
			build(1,1,n);
			for(res j=1;j<=n;j++)modify(1,1,n,pre[j]+1,j,1),dp[j]=query(1,1,n,1,j);
		}
		printf("%d\n",dp[n]);
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}