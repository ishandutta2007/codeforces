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
struct ew{
	int pos,l,r,val;
	bool operator <(const ew x)const{
		return val>x.val;
	}
}h[200005];
priority_queue <ew> q;
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,C,p[1000002],c1,c2,v[200002],n0,n1;
char s[1000002],S[1000002];
inline int solve(re int x){
	sort(p+1,p+m+1);
	re int s=0,anss=0;
	for(re int i=1;i<=m;++i){
		s+=p[i];
		if(s>x)return anss;
		++anss;
	} 
	return anss;
}
inline int Try(){
	ans=0;
	re int num=0;
	while(c1&&c2)--c1,--c2,ans+=A+B,++num;
	if(c2){
		if(B-C>0){
			ans+=min(n0-num,n1-num-1)*(B-C);
		}
		return ans;
	}
	re int i=1,j;
	while(s[i]=='1')++i;
	for(;i<=n;i=j+1){
		j=i;if(s[j]=='1')continue;
		while(s[j+1]=='0')++j;
		if(j==n||i==1)continue;
		p[++m]=j-i;
	}
	return ans+(B>C?solve(num)*(B-C):0)+(c1?A:0);
}
signed main(){
	t=read();
	while(t--){
		n=read(),A=read(),B=read(),C=read();
		scanf("%s",s+1);
		m=0;c1=c2=n0=n1=0;
		for(re int i=1;i<=n;++i){
			if(s[i]==s[i-1]){
				if(s[i]=='0')++c1;
				else ++c2;
			}
			if(s[i]=='0')++n0;
			else ++n1;
		}
		re int sss=Try();
		m=0;c1=c2=0;
		for(re int i=1;i<=n;++i){
			if(s[i]==s[i-1]){
				if(s[i]=='0')++c1;
				else ++c2;
			}
		}
		if(c2)--n1,--c2,sss=max(sss,Try()+B);
		printf("%lld\n",sss);
	}
}