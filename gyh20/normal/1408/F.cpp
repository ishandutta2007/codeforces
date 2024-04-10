#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int m,ans1[500002],ans2[500002],sum,fst,la;
inline void work(re int n,re int k){
	for(re int j=0;(1<<j)<=n;++j)
	for(re int ii=1;ii+(1<<j)<=n;ii+=(1<<(j+1))){
		for(re int i=ii;i<ii+(1<<j);++i)
		ans1[++m]=i+k,ans2[m]=i+k+(1<<j);
	}
}
int main(){
	int n=read();
	int ss=1,nn=n;
	while(ss<n)ss<<=1;ss>>=1;n=ss<<1;
	work(ss,0);
	work(ss,ss);n=nn;
	for(re int i=1;i<=m;++i){if(ans1[i]>n)ans1[i]=ans1[i]-n;if(ans2[i]>n)ans2[i]-=n;
	}
	printf("%d\n",m);
	for(re int i=1;i<=m;++i)printf("%d %d\n",ans1[i],ans2[i]);
}