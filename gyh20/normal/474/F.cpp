#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	int x,y;
}T[400002],ans;
inline int gcd(re int x,re int y){return y?gcd(y,x%y):x;}
inline node ADD(node x,node y){
	re int g=gcd(x.x,y.x);
	node tmp=(node){g,0};
	if(g==x.x)tmp.y+=x.y;
	if(g==y.x)tmp.y+=y.y;
	return tmp;
}
int n,a[100002];
inline void build(re int p,re int l,re int r){
	if(l==r){
		T[p]=(node){a[l],1};
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	T[p]=ADD(T[p<<1],T[p<<1|1]);
}
inline void ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){
		ans=ADD(ans,T[p]);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)ask(p<<1,l,mid,x,y);
	if(y>mid)ask(p<<1|1,mid+1,r,x,y);
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	re int q=read();
	while(q--){
		re int l=read(),r=read();ans=(node){0,0};
		ask(1,1,n,l,r);
		printf("%d\n",r-l+1-ans.y);
	}
}