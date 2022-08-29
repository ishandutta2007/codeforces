#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
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
int t,n,m,A,B,a[1000002],b[1000002],ans,sz1[32],sz2[32];
char s[1000002];
vector<int>pos[150002];
int main(){
	t=read();
	while(t--){
		for(re int i=1;i<=150000;++i)pos[i].clear();
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),pos[a[i]].push_back(i);
		ans=-1;
		for(re int i=1;i<=150000;++i)
			for(re int j=1;j<pos[i].size();++j)
				ans=max(ans,pos[i][j-1]+n-pos[i][j]);
		printf("%d\n",ans);
	}
}