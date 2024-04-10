#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n;
char v[1000002];
ull val[1000002],V[1000002],O[1000002];
map<ull,int>vis;
int main(){
	n=read(),srand(time(0)); 
	for(re int i=2;i<=n;++i)
		if(!v[i]){
			val[i]=(1ll*rand()<<48)|(1ll*rand()<<32)|(rand()<<16)|rand();
			for(re int j=i;j<=n;j+=i){
				re int x=j;
				while(x%i==0)V[j]^=val[i],x/=i;
				v[j]=1;
			}
		}
	for(re int i=1;i<=n;++i)V[i]^=V[i-1],O[i]=V[i];
	for(re int i=1;i<=n;++i)V[i]^=V[i-1];
	if(!V[n]){
		printf("%d\n",n);
		for(re int i=1;i<=n;++i)printf("%d ",i);
		return 0;
	}
	for(re int i=1;i<=n;++i)if(O[i]==V[n]){
		printf("%d\n",n-1);
		for(re int j=1;j<=n;++j)if(j^i)printf("%d ",j);
		return 0;
	}
	for(re int i=1;i<=n;++i)vis[O[i]]=i;
	for(re int i=1;i<=n;++i)if(vis.count(V[n]^O[i])){
		printf("%d\n",n-2);re int xx=vis[V[n]^O[i]];
		for(re int j=1;j<=n;++j)if(j^i&&j^xx)printf("%d ",j);
		return 0;
	}
	--n;
	vis.clear();
	for(re int i=1;i<=n;++i)vis[O[i]]=i;
	for(re int i=1;i<=n;++i)if(vis.count(V[n]^O[i])){
		printf("%d\n",n-2);re int xx=vis[V[n]^O[i]];
		for(re int j=1;j<=n;++j)if(j^i&&j^xx)printf("%d ",j);
		return 0;
	}
}