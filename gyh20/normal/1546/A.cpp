#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[102],b[102],A[1000002],B[1000002],tot;
vector<int>v1,v2;
int main(){
	t=read();
	while(t--){
		re int s1=0,s2=0;tot=0;
		n=read(),v1.clear(),v2.clear();
		for(re int i=1;i<=n;++i)s1+=(a[i]=read());
		for(re int i=1;i<=n;++i)s2+=(b[i]=read());
		for(re int i=1;i<=n;++i)if(a[i]<b[i])v1.push_back(i);else if(a[i]!=b[i])v2.push_back(i);
		if(s1^s2){
			puts("-1");
			continue;
		}
		re int pos=0,sum=0;
		for(re int i=0;i<v1.size();++i)sum+=b[v1[i]]-a[v1[i]];
		printf("%d\n",sum);
		for(re int i=0;i<v1.size();++i){
			re int dlt=b[v1[i]]-a[v1[i]];
			while(dlt--){
				if(b[v2[pos]]==a[v2[pos]])++pos;
				printf("%d %d\n",v2[pos],v1[i]),--a[v2[pos]];
			}
		}
	}
}