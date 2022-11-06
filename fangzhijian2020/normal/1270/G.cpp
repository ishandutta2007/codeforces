#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,vis[1000005],a[1000005],tot,ans[1000005];
int main(){
	T=read()+1;
	while(--T){
		n=read();tot=0;
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1;i<=n;++i)a[i]=read();
		int now=1;
		while(1){
			if(vis[now])break;
			vis[now]=1;now=now-a[now];
		}
		while(1){
			if(vis[now]==2)break;
			vis[now]=2;ans[++tot]=now;now=now-a[now];
		}
		cout<<tot<<"\n";
		for(int i=1;i<=tot;++i)cout<<ans[i]<<" ";puts("");
	}
	return 0;
}