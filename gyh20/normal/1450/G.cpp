#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,A,B,v[202],tot,L[1<<20],R[1<<20],Num[1<<20];
char s[5002],ia[1<<20],pp[5002];
vector<char>ans;
int main(){
	n=read(),A=read(),B=read();
	scanf("%s",s+1),memset(v,-1,sizeof(v));
	for(re int i=1;i<=n;++i)if(v[s[i]]==-1)v[s[i]]=tot++,pp[tot-1]=s[i];
	for(re int i=1;i<=n;++i)s[i]=v[s[i]];
	for(re int i=1;i<=n;++i){
		if(!L[1<<s[i]])L[1<<s[i]]=i;
		R[1<<s[i]]=i,++Num[1<<s[i]];
	}
	for(re int i=1;i<(1<<tot);++i)if(!Num[i]){
		re int x=i&(-i);
		L[i]=min(L[x],L[i^x]),R[i]=max(R[x],R[i^x]);
		Num[i]=Num[x]+Num[i^x]; 
	}
	ia[0]=1;
	for(re int i=1;i<(1<<tot);++i){
		re int z=0;
		for(re int j=0;j<tot;++j)
			if(i&(1<<j)){
				z|=1<<j;
				if(ia[i^(1<<j)]&&(R[i]-L[i]+1)*A<=Num[i]*B)ia[i]=1;
				if(ia[z]&&ia[i^z])ia[i]=1;
			}
	}
	for(re int i=0;i<tot;++i)if(ia[((1<<tot)-1)^(1<<i)])ans.push_back(pp[i]);
	sort(ans.begin(),ans.end()),printf("%u ",ans.size());
	for(auto c:ans)printf("%c ",c);
}