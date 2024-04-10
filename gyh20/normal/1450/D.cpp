#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[300002],t,ans[300002],pos,ia,sum[300002];
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
set<int>s;
set<int>::iterator it,it1;
vector<int>v[300002];
int main(){
	t=read();
	while(t--){
		n=read(),ia=1,pos=0;s.clear();re int mn=1e9;
		for(int i=1;i<=n;++i)ans[i]=sum[i]=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)if(sum[a[i]])ia=0;else ++sum[a[i]];
		for(int i=1;i<=n;++i)ans[i]=sum[i]=0;
		ans[1]=ia;
		for(int i=1;i<n;++i)a[i]=min(a[i],a[i+1]),++sum[a[i]];
		for(int i=1;i<n;++i){
			if(!sum[i])break;
			ans[n-i+1]=1;
			if(sum[i]>1)break;
		}
		for(int i=1;i<=n;++i)putchar(ans[i]?'1':'0');
		puts("");
	}
}