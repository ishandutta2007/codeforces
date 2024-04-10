//2019.4.28 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-12
#define RG register
inline int read(){
	res s=0,w=1,ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
namespace MAIN{
	struct P{
		int l,r,x,y;
		P() {}
		P(res l,res r,res x,res y):l(l),r(r),x(x),y(y) {}
		inline bool operator < (const P &b) const {
			return l!=b.l?l<b.l:r<b.r;
		}
	}e;
	set<P> S;
	int n,m;
	char opt[10];
	inline void MAIN(){
		n=read(),m=read(),S.insert(P(0,0,1,1)),S.insert(P(1,n,1,1));
		while(m--){
			res x=read(),y=read(),ans=0;
			scanf("%s",opt),e=*--S.lower_bound(P(x,n+1,1,1));
			if(e.l<=x&&x<=e.r){
				S.erase(e);
				if(opt[0]=='L')ans=x-e.x+1,S.insert(P(e.l,x-1,e.x,y+1)),S.insert(P(x+1,e.r,e.x,e.y));
				else ans=y-e.y+1,S.insert(P(e.l,x-1,e.x,e.y)),S.insert(P(x+1,e.r,x+1,e.y));
			}
			printf("%d\n",ans);			
		}
	}
}
int main(){
	MAIN::MAIN();
	return 0;
}