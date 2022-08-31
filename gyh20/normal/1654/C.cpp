#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],b[1000002],A,B,ans;
char s[1000002];
map<int,int>V,K;
signed main(){
	t=read();
	while(t--){
		n=read(),ans=0;V.clear(),K.clear();
		for(re int i=1;i<=n;++i)a[i]=read(),ans+=a[i],++V[a[i]];
		sort(a+1,a+n+1);
		n=1,a[1]=ans;re bool ia=1;K[ans]=1;
		for(re int i=1;i<=n;++i){
			K[a[i]]-=V[a[i]];
			if(K[a[i]]<0||a[i]==0){
				ia=0;
				break;
			}
			re int v=K[a[i]],v1=a[i]>>1,v2=a[i]+1>>1;
			if(v==0)continue;
			if(!K.count(v2))a[++n]=v2,K[v2]=0;
			if(!K.count(v1))a[++n]=v1,K[v1]=0;
			K[v1]+=v,K[v2]+=v;
		}
		puts(ia?"YES":"NO");
	}
}