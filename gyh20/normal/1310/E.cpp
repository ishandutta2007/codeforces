// LUOGU_RID: 90548015
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
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,t,ans,f[2022],g[2022][102];
inline bool ck(vector<int>A,int k){
	if(k==3){
		vector<int>B;
		for(re int i=0;i<A.size();++i)for(re int j=0;j<A[A.size()-i-1];++j)B.push_back(i+1);
		int sum=0;
		for(re int i=0;i<B.size();++i)sum+=B[B.size()-i-1]*(i+1);
		return sum<=n;
	}
	while(k--){
		vector<int>B;
		int o=0;
		for(auto z:A)o+=z;
		if(o>n)return 0;
		if(k==0)return 1;
		for(re int i=0;i<A.size();++i)for(re int j=0;j<A[A.size()-i-1];++j)B.push_back(i+1);
		A=B;
	}
}
inline void dfs(re int x,vector<int>A){
	if(A.size()&&A[A.size()-1]==x-1)++ans;
	A.push_back(x);if(!ck(A,m))return;A.pop_back();
	for(re int i=0;(i<=1)||(ck(A,m));++i)dfs(x+1,A),A.push_back(x);
}
inline int calc(re int x,re int y){
	if(y*(y+1)>=x*2)return y*(y+1)==x*2;
	if(~g[x][y])return g[x][y];
	return g[x][y]=Mod(calc(x-y*(y+1)/2,y)+calc(x,y+1));
}
int main(){
	vector<int>A;
	n=read(),m=read(),memset(g,-1,sizeof(g));
	if(m==1){
		f[0]=1;
		for(re int i=1;i<=n;++i)for(re int j=i;j<=n;++j)add(f[j],f[j-i]);
		int ans=0;
		for(re int i=1;i<=n;++i)add(ans,f[i]);
		printf("%d",ans);return 0; 
	}
	if(m==2){
		re int s=0;
		for(re int i=1;i<=n;++i)add(s,calc(i,1));
		return printf("%d",s),0;
	}
	dfs(1,A);
	printf("%d",ans);
}