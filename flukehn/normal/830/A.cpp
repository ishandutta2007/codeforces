#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
const int N=2011,inf=0x7fffffff;
int n,K,a[N],b[N],M,ans=inf;
inline int calc(int l){
	int ret=0;
	for(int i=1;i<=n;i++){
		ret=max(ret,abs(a[i]-b[l+i-1])+abs(b[l+i-1]-M));
		if(ret>=ans)return ret;}
	return ret;
}
int main(){
	n=rd(),K=rd(),M=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1;i<=K;i++)b[i]=rd();
	sort(a+1,a+n+1),sort(b+1,b+K+1);
	for(int i=1;i<=K-n+1;i++)ans=min(ans,calc(i));
	printf("%d\n",ans);
}