#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,m,Q,p[N],a[N],pos[N],nxt[N],ans[N],f[N][25];
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main(){
	n=read();
	m=read();
	Q=read();
	ans[m+1]=m+1;
	for(int i=1;i<=n;++i){
		p[i]=read();
	}
	for(int i=1;i<=m;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		nxt[p[i-1]]=p[i];
	}
	nxt[p[n]]=p[1];
	for(int i=1;i<=n;++i){
		pos[i]=m+1;
	}
	for(int i=m;i>=1;--i){
		f[i][0]=pos[nxt[a[i]]]; 
		pos[a[i]]=i;
		for(int k=0;k<=20;++k){
			f[m+1][k]=m+1;
		}
		for(int k=1;k<=20;++k){
			f[i][k]=f[f[i][k-1]][k-1];
		}
		int Step=n-1;
		ans[i]=i;
		for(int k=20;k>=0;--k){
			if(Step>=(1<<k)){
				Step-=(1<<k);
				ans[i]=f[ans[i]][k];
			}
		}
		ans[i]=min(ans[i],ans[i+1]);
	}
	for(int i=1;i<=Q;++i){
		int l=read(),r=read();
		printf(ans[l]<=r?"1":"0");
	}
	return 0;
}