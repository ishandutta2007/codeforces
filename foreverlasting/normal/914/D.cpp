//2018.10.24 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=5e5+10;
namespace MAIN{
	inline int gcd(res x,res y){
		while(y){
			res t=x;
			x=y,y=t%x;
		}
		return x;
	}
	int GCD[N<<2];
	inline void pushup(const res &rt){
		GCD[rt]=gcd(GCD[rt<<1],GCD[rt<<1|1]);
	}
	void build(const res &rt,const res &l,const res &r){
		if(l==r){GCD[rt]=read();return;}
		res mid=(l+r)>>1;
		build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	int query(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va){
		if(GCD[rt]%va==0)return 0;
		if(l==r)return 1;
		res mid=(l+r)>>1,ret=0;
		if(L<=mid)ret+=query(rt<<1,l,mid,L,R,va);
		if(ret>=2)return ret;
		if(R>mid)ret+=query(rt<<1|1,mid+1,r,L,R,va);
		return ret;
	}
	void modify(const res &rt,const res &l,const res &r,const res &p,const res &va){
		if(l==r){GCD[rt]=va;return;}
		res mid=(l+r)>>1;
		if(p<=mid)modify(rt<<1,l,mid,p,va);
		else modify(rt<<1|1,mid+1,r,p,va);
		pushup(rt);
	}
	int n;
	inline void MAIN(){
		n=read();
		build(1,1,n);
		res Q=read();
		while(Q--){
			res opt=read();
			if(opt==1){
				res l=read(),r=read(),x=read();
				if(query(1,1,n,l,r,x)>=2)puts("NO");
				else puts("YES");
			}
			else {
				res x=read(),y=read();
				modify(1,1,n,x,y);
			}
		}
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}