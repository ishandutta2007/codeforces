#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,num,a[300002],b[300002],M,F[300002];
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline void Add(re int x,re int y){
	if(x>n)return;
	num-=a[x]!=b[x];
	add(a[x],y);
	num+=a[x]!=b[x];
}
int main(){
	n=read(),m=read(),M=read();
	F[1]=1;
	for(re int i=2;i<=n;++i)F[i]=Mod(F[i-1]+F[i-2]);
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=n;i;--i){
		add(a[i],M-a[i-1]),add(b[i],M-b[i-1]);
		if(i>1)add(a[i],M-a[i-2]),add(b[i],M-b[i-2]);
		num+=a[i]!=b[i];
	}
	while(m--){
		char c[4];
		scanf("%s",c);
		re int l=read(),r=read();
		if(l==r){
			if(c[0]=='A')Add(l,1),Add(l+1,M-1),Add(l+2,M-1);
			else Add(l,M-1),Add(l+1,1),Add(l+2,1);
		}
		else{
			if(c[0]=='A')Add(l,1),Add(r+1,M-F[r-l+1]),Add(r+1,M-F[r-l]),Add(r+2,M-F[r-l+1]);
			else Add(l,M-1),Add(r+1,F[r-l+1]),Add(r+1,F[r-l]),Add(r+2,F[r-l+1]);
		}
		puts(num?"NO":"YES");
	}
}