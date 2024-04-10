#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a[100002],ans,f[100002],sum;
int vis[100002];
int main(){
	n=read(),m=read();ans=n*3-2;
	for(re int i=1;i<=m;++i)a[i]=read();
	for(re int i=m;i;--i){
		if(!vis[a[i]]){
			vis[a[i]]=i;sum=0;
			for(int j=a[i]-1;j<=a[i]+1;++j)sum+=(vis[j]>0);
			f[i]=sum;
		}
		else{
			ans+=f[vis[a[i]]];sum=0;
			for(int j=a[i]-1;j<=a[i]+1;++j)sum+=(vis[j]>0);
			f[i]=sum;
		}
		vis[a[i]]=i;
		ans-=f[i];
	}
	printf("%d\n",ans);
	
}