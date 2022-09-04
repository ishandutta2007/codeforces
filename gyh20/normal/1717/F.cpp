#include<bits/stdc++.h>
#define re register
using namespace std;
#define gc getchar
inline int read(){
	re int t=0;cin>>t;
	return t;
}
int n,a[1000002],b[1000002],c[1000002],val[1000002],st[1000002],m,s[1000002],V[1000002];
inline int calc(re int x,re int y){
	if(s[x])return y*y;
	return 0; 
}
inline int ck(re int x,re int y){
	return calc(x,V[x]-1)+calc(y,V[y]+1);
}
inline void Ins(re int x,re int y){--V[x];++V[y];}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)s[i]=read();
	for(re int i=1;i<=n;++i)V[i]=-read();
	for(re int i=1;i<=m;++i){
		a[i]=read(),b[i]=read();
		if(ck(b[i],a[i])<ck(a[i],b[i]))swap(a[i],b[i]);
		Ins(a[i],b[i]);
	}
	double st=clock();
	while(1.0*(clock()-st)/CLOCKS_PER_SEC<1.95){
		re bool f=0,f1=0;
		for(re int i=1;i<=m;++i){
			Ins(b[i],a[i]);
			if(ck(b[i],a[i])<ck(a[i],b[i]))swap(a[i],b[i]),f1=1;
			Ins(a[i],b[i]);
		}
		for(re int i=1;i<=n;++i)if(s[i]&&V[i])f=1;
		if(!f){
			puts("YES");
			for(re int i=1;i<=m;++i)printf("%d %d\n",a[i],b[i]);
			return 0;
		}
		else if(!f1){
		for(re int i=1;i<=m;++i){
			Ins(b[i],a[i]);
			if(ck(b[i],a[i])<=ck(a[i],b[i]))swap(a[i],b[i]),f1=1;
			Ins(a[i],b[i]);
		}
			
		}
	}puts("NO");
}