#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
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
int c[200002],b[200002],N,f[200002],ans,g[200002],O[200002];
inline void addd(re int x,re int y){
	for(;x<=N;x+=x&(-x))add(c[x],y);
}
inline int ask(re int x,re int s=0){
	for(;x;x^=x&(-x))add(s,c[x]);
	return s;
}
inline void Get(vector<int>&a,re int x){
	int n=a.size()-1;N=n;
	for(re int i=1;i<=n;++i)b[i]=a[i];
	sort(b+1,b+n+1);
	for(re int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(re int i=n;i;--i){
		f[i]=Mod(ask(n)-ask(a[i])+M);
		if(x==1||i==n)add(f[i],1);
		addd(a[i],f[i]),add(ans,1ll*x*f[i]%M*g[O[i]]%M);
	}
	for(re int i=1;i<=n;++i)addd(a[i],M-f[i]);
}
int t,n,m,a[200002],A,B,stk[200002],tp,v[200002],p[200002];
char s[1000002];
inline bool cmp(re int x,re int y){
	return a[x]==a[y]?x>y:a[x]<a[y];
}
int main(){
	t=read();
	while(t--){
		n=read();
		vector<int>tmp;ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),p[i]=i,v[i]=0,b[i]=a[i],O[i]=i;
		sort(b+1,b+n+1);
		for(re int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
		N=n;
		for(re int i=1;i<=n;++i){
			g[i]=ask(a[i]-1),add(g[i],1);
			addd(a[i],g[i]);
		}
		for(re int i=1;i<=n;++i)addd(a[i],M-g[i]);
		for(re int i=0;i<=n;++i)tmp.push_back(a[i]);
		re int mx=0;
		for(re int i=n;i;--i){
			if(a[i]==mx)add(ans,M-g[i]);
			mx=max(mx,a[i]);
		}
		Get(tmp,1);
		tp=0;
		stk[tp=1]=n;
		for(re int i=n-1;i;--i)if(a[i]>a[stk[tp]])stk[++tp]=i;
		sort(p+1,p+n+1,cmp);
		for(re int i=1;i<=tp;++i)v[stk[i]]=1;
		for(re int i=1,j;i<=n;i=j+1){
			int tot=0;j=i;
			while(1){
				O[++tot]=p[j];
				if(v[p[j]])break;
				++j;
				if(j>n){
					break;
				}
			}
			if(j>n)break;
			tmp.clear();tmp.push_back(0);
			sort(O+1,O+tot+1);
			while(!v[O[tot]])--tot;
			for(re int k=1;k<=tot;++k)tmp.push_back(a[O[k]]);
			Get(tmp,M-1);
		}
		printf("%d\n",ans);
	}
}