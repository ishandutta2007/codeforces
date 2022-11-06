#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,k,a[131072];
struct node{
	int Max,se;
//	node(){Max=se=0;}
	void clear(){Max=se=0;}
	
}f[131072];
node MAX(node a,node b){
	node c;
	c.Max=max(a.Max,b.Max);
	c.se=max(c.Max==a.Max?a.se:a.Max,c.Max==b.Max?b.se:b.Max);
	return c;
}	
void FMT(int n){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;++j){
			if(j&i)f[j]=MAX(f[j],f[j^i]);
		}
	}
}
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();f[a[i]]=MAX(f[a[i]],(node){i,0});
		}
		int m=1;while(m<=n)m<<=1;FMT(m);long long ans=-1e18;
		for(int i=0;i<=m;++i){
			if(f[i].se){
				ans=max(ans,1ll*f[i].Max*f[i].se-1ll*k*i);
			}
		}
		for(int i=0;i<=m;++i)f[i].clear();
		cout<<ans<<"\n";
	}
	return 0;
}