#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[200002],t,ans;
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
using namespace std;
map<int,int>v;
int main(){
	t=read();
	while(t--){
		v.clear();
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		ans=0;
		for(re int i=1;i<=n;++i)for(re int j=1;j<i;++j)if(!v[a[i]-a[j]])++ans,v[a[i]-a[j]]=1;
		printf("%d\n",ans);
	}
}