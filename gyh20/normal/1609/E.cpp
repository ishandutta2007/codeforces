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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct Mat{
	int a[4][4];
	inline void clr(){
		for(re int i=1;i<=3;++i)
			for(re int j=1;j<=3;++j)
				a[i][j]=1e9;
	}
}X,Y,Z,T[400002];
inline Mat Get(re int x){
	if(x==0)return X;
	if(x==1)return Y;
	return Z;
}
inline Mat mul(Mat A,Mat B){
	Mat C;C.clr();
	for(re int i=1;i<=3;++i)
		for(re int j=1;j<=3;++j)
			for(re int k=1;k<=3;++k)
				C.a[i][k]=min(C.a[i][k],A.a[i][j]+B.a[j][k]);
	return C;
}
char s[100002],c[12];
inline void build(re int p,re int l,re int r){
	if(l==r){
		T[p]=Get(s[l]-'a');
		return; 
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	T[p]=mul(T[p<<1],T[p<<1|1]);
}
inline void cg(re int p,re int l,re int r,re int x,re Mat y){
	if(l==r){
		T[p]=y;
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y);
	else cg(p<<1|1,mid+1,r,x,y);
	T[p]=mul(T[p<<1],T[p<<1|1]);
}
int t,n,m,a[1000002],ans;
int main(){
	X.clr(),Y.clr(),Z.clr();
	for(re int i=1;i<=3;++i)X.a[i][i]=0,Y.a[i][i]=0,Z.a[i][i]=0;
	X.a[1][1]=1;
	X.a[1][2]=0;
	Y.a[2][2]=1;
	Y.a[2][3]=0;
	Z.a[3][3]=1;
	n=read(),m=read();
	scanf("%s",s+1);
	build(1,1,n);
	while(m--){
		re int x=read();scanf("%s",c+1);
		cg(1,1,n,x,Get(c[1]-'a'));
		printf("%d\n",min(T[1].a[1][1],min(T[1].a[1][2],T[1].a[1][3])));
	}
}