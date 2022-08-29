#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],la;
map<int,int>v[100002];
inline int ask(re int x,re int y){
	if(x==y)return 0;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return v[x][y]=read();
}
inline void solve(re int l,re int r){
	if(l==r){
		printf("! %d\n",l);
		fflush(stdout);
		return;
	}
	re int pos=ask(l,r),mid=l+r>>1;
		if(pos<=mid){
			if(ask(l,mid)==pos)la=pos,solve(l,mid);
			else solve(mid+1,r);
		}
		else{
			if(ask(mid+1,r)==pos)la=pos,solve(mid+1,r);
			else solve(l,mid);
		}
}
signed main(){
	n=read();
	re int x=ask(1,n);
	if(ask(1,x)==x){
		re int l=1,r=x-1;
		while(l<=r){
			re int mid=l+r>>1;
			if(ask(mid,x)!=x)r=mid-1;
			else ans=mid,l=mid+1;
		}
	}
	else{
		re int l=x+1,r=n;
		while(l<=r){
			re int mid=l+r>>1;
			if(ask(x,mid)!=x)l=mid+1;
			else ans=mid,r=mid-1;
		}
	}
	printf("! %d",ans);
	fflush(stdout);
}