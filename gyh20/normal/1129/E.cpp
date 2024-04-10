#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,siz[502],p[502],pos,fa[502],cur;
basic_string<int>A,B;
inline bool cmp(re int x,re int y){return siz[x]<siz[y];}
inline int ask(basic_string<int>&X,basic_string<int>&Y,re int rt){
	if(X.size()==0||Y.size()==0)return 0;
	printf("%u\n",X.size());for(auto z:X)printf("%d ",z);puts("");
	printf("%u\n",Y.size());for(auto z:Y)printf("%d ",z);puts("");
	printf("%d\n",rt);fflush(stdout);return read();
}
inline int solve(basic_string<int>&X){
	if(X.size()==1)return X[0];
	basic_string<int>L,R;
	for(int i=0;i<X.size()+1>>1;++i)L+=X[i];
	for(int i=X.size()+1>>1;i<X.size();++i)R+=X[i];
	if(ask(L,A,cur))return solve(L);
	return solve(R);
}
int main(){
	n=read(),siz[1]=n,p[1]=1;A+=1;
	for(re int i=2;i<=n;++i)B+=i,p[i]=i;
	for(re int i=2;i<=n;++i)siz[i]=ask(A,B,i);
	sort(p+1,p+n+1,cmp),B.clear();cur=p[1];
	for(re int i=1;i<=n;B+=p[i],++i,cur=p[i])
		while(ask(B,A,p[i])){
			pos=solve(B),fa[pos]=p[i];
			basic_string<int>C;
			for(auto z:B)if(z^pos)C+=z;
			B=C;
		}
	puts("ANSWER");
	for(re int i=2;i<=n;++i)printf("%d %d\n",i,fa[i]);fflush(stdout);
}