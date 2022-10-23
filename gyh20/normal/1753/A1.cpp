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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,t,a[1000002],ans;
vector<int>A,B;
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;A.clear(),B.clear();
		for(re int i=1;i<=n;++i)scanf("%d",&a[i]),ans+=a[i];
		if(n&1){
			puts("-1");
			continue;
		}
		for(re int i=1;i<=n;++i){
			if(i!=n&&a[i+1]==1&&ans>0)A.push_back(i),B.push_back(i+1),++i,ans-=2;
			else if(i!=n&&a[i+1]==-1&&ans<0)A.push_back(i),B.push_back(i+1),++i,ans+=2;
			else A.push_back(i),B.push_back(i);
		}
		printf("%u\n",A.size());
		for(re int i=0;i<A.size();++i)printf("%d %d\n",A[i],B[i]);
	}
}