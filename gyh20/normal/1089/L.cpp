#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],A,B,b[1000002],k;
long long ans;
vector<int>G[100002],X;
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)b[i]=read(),G[a[i]].push_back(b[i]);
	for(re int i=1;i<=m;++i){
		sort(G[i].begin(),G[i].end()),reverse(G[i].begin(),G[i].end());
		if(G[i].size()){
			++k;
			for(re int j=1;j<G[i].size();++j)X.push_back(G[i][j]);
		}
	}
	sort(X.begin(),X.end());
	for(re int i=0;i<m-k;++i)ans+=X[i];
	printf("%lld",ans);
}