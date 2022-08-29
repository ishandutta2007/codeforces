#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,g[1000002],X[1000002],T[1000002],f[1000002],inf=1e12;
inline int Abs(re int x){return x>0?x:-x;}
inline void gmn(re int &x,re int y){(y<x)&&(x=y);}
signed main(){
	n=read();
	for(re int i=1;i<=n;++i){
		T[i]=read(),X[i]=read(),g[i]=inf;
	}
	for(re int i=1;i<=n;++i){
		re int pos=i,mx=-1;
		if(Abs(X[i]-X[i-1])<=T[i]-g[i-1])gmn(g[i],T[i]-min(T[i]-g[i-1]-Abs(X[i]-X[i-1]),(X[i]==X[i-1]?T[i]:(T[i]-T[i-1]))));
		if(f[i-1]&&Abs(X[i]-X[i-2])<=T[i]-T[i-2])gmn(g[i],T[i]-min(T[i]-T[i-2]-Abs(X[i]-X[i-2]),T[i]-T[i-1]));
		if(X[i]==X[i-1]){
f[i]=g[i]<=T[i];
			mx=max(mx,T[i]-T[i-1]);
			pos=i-1;
			while(pos&&X[pos]==X[pos-1])mx=max(mx,(T[pos]-max(T[pos-1],g[i]))>>1),--pos;
			g[i]=max(g[i],T[i]-mx);
		}
		for(re int j=i-2;~j&&!f[i];--j){
			if(g[j]<=T[j]&&max(Abs(X[j]-X[i]),X[i]==X[j]?0:(T[j]-g[j]))+Abs(X[i]-X[j+1])<=T[j+1]-g[j])f[i]=1;
			if(f[j]&&(X[i]==X[j]?0:(max(Abs(X[i]-X[j-1]),T[j]-T[j-1])+Abs(X[i]-X[j+1])))<=T[j+1]-T[j-1])f[i]=1;
			if(T[j+1]-T[j]<Abs(X[j]-X[j+1]))break;
		}
	}
	puts(g[n]<=T[n]||f[n]?"YES":"NO");
}