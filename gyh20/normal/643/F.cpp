#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#define re register
#define uint unsigned int
int v[132],n,p,q,vv[132];
uint C[132],sum=1,*ed;
inline void Add(re int s){
	for(re int j=2;j<=p;++j)if(!vv[j])while(s%j==0)s/=j,++v[j];
	sum*=s;
}
inline void del(re int s){
	for(re int j=2;j<=s;++j)if(!vv[j])while(s%j==0)s/=j,--v[j];
}
inline uint ask(re int x,re int y){
	re uint ans=1;
	Add(x-y+1),del(y);
	for(re int i=2;i<=p;++i)for(re int j=1;j<=v[i];++j)ans*=i;
	return ans*sum;
}
int main(){
	scanf("%d%d%d",&n,&p,&q);if(p>=n)p=n-1;C[0]=1;
	for(re int i=2;i<=p;++i)for(re int j=i+i;j<=p;j+=i)vv[j]=1;
	for(re int i=1;i<=p;++i)C[i]=ask(n,i);ed=&C[p];
	re uint ans=0;
	for(re int i=1;i<=q;++i){
		re uint s=0,pw=1;
		for(re uint *j=C;j<=ed;++j)s+=(*j)*pw,pw*=i;
		ans^=s*i;
	}
	printf("%u",ans);
}