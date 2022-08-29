#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1002],b[1002],ans[20002],cnt,c[1002],fans[100002],cnt1;
bool vis[1002];
inline void mex(re int x){ans[++cnt]=x;
	re int sum=0;
	memset(b,0,sizeof(b));
	for(re int i=1;i<=n;++i)++b[a[i]];
	while(b[sum])++sum;
	a[x]=sum;
}
inline int gm(re int x){
	re int sum=0;
	memset(b,0,sizeof(b));
	for(re int i=1;i<=n;++i)++b[a[i]];
	while(b[sum])++sum;
	return sum;
}
inline void ck(){
	if(cnt1<=cnt)return;
	for(re int i=1;i<=cnt;++i)fans[i]=ans[i];
	cnt1=cnt;
}
int main(){
	t=read();
	while(t--){cnt1=1e9;
		n=read();cnt=0;for(re int i=1;i<=n;++i)c[i]=a[i]=read();
		memset(vis,0,sizeof(vis));vis[0]=1;
		for(re int ii=1;ii<=n;++ii)if(vis[a[ii]]&&a[ii]<ii-1&&gm(ii)>a[ii])mex(ii);else vis[a[ii]]=1;
		for(re int i=1;i<=n;++i){
			if(a[i]!=i-1){
			for(re int j=i+1;j<=n;++j)if(a[j]==i-1)mex(j);
			mex(i);	}
		}
		ck();
		cnt=0;for(re int i=1;i<=n;++i)a[i]=c[i];
		memset(vis,0,sizeof(vis));
		for(re int i=1;i<=n;++i)if(vis[a[i]])mex(i);else vis[a[i]]=1;for(re int i=1;i<=n;++i)if(a[i]==0)mex(i);
		for(re int i=n;i;--i){
			if(a[i]!=i){
			re int pos=i;
			do{
				re int xxx=pos;
				pos=a[pos];
				mex(xxx);
			}while((pos^i));
			mex(i);
			}
		}
		ck();cnt=0;for(re int i=1;i<=n;++i)a[i]=c[i];
		memset(vis,0,sizeof(vis));mex(1);
		for(re int i=1;i<=n;++i)if(vis[a[i]]&&a[i]<i)mex(i);else vis[a[i]]=1;
		for(re int i=1;i<=n;++i){
			if(a[i]!=i-1){
			for(re int j=i+1;j<=n;++j)if(a[j]==i-1)mex(j);
			mex(i);	}
		}ck();
		printf("%d\n",cnt1);
		for(re int i=1;i<=cnt1;++i)printf("%d ",fans[i]);puts("");
	}
}