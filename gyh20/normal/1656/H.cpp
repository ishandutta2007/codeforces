#include<bits/stdc++.h>
#define re register
#define int __int128
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline void write(re int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline int gcd(re int x,re int y){return y?gcd(y,x%y):x;}
inline int lcm(re int x,re int y){if(!x||!y)return x+y;return x/gcd(x,y)*y;}
struct SGT{
	int L[4002];
	inline void cg(re int p,re int l,re int r,re int x,re int y){
		if(l==r){L[p]=y;return;}
		re int mid=l+r>>1;
		if(x<=mid)cg(p<<1,l,mid,x,y);
		else cg(p<<1|1,mid+1,r,x,y);
		L[p]=lcm(L[p<<1],L[p<<1|1]);
	}
}T1[1002],T2[1002];
int t,n,m,a[1002],b[1002];
char ua[1002],ub[1002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)a[i]=read(),ua[i]=0;
		for(re int i=1;i<=m;++i)b[i]=read(),ub[i]=0;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j){
				re int x=gcd(a[i],b[j]);
				T1[i].cg(1,1,m,j,x),T2[j].cg(1,1,n,i,x);
			}
		while(1){
			re bool ia=1;
			for(re int i=1;i<=n;++i)
				if((a[i]^1)&&(T1[i].L[1]^a[i])){
					a[i]=1,ia=0,ua[i]=1;
					for(re int j=1;j<=m;++j)T2[j].cg(1,1,n,i,1);
				}
			for(re int i=1;i<=m;++i)
				if((b[i]^1)&&(T2[i].L[1]^b[i])){
					b[i]=1,ia=0,ub[i]=1;
					for(re int j=1;j<=n;++j)T1[j].cg(1,1,m,i,1);
				}
			if(ia)break;
		}
		vector<int>A,B;
		for(re int i=1;i<=n;++i)if(!ua[i])A.push_back(a[i]);
		for(re int j=1;j<=m;++j)if(!ub[j])B.push_back(b[j]);
		if(min(A.size(),B.size())==0)puts("NO");
		else{
			puts("YES");
			printf("%d %d\n",A.size(),B.size());
			for(auto z:A)write(z),putchar(' ');puts("");
			for(auto z:B)write(z),putchar(' ');puts("");
		}
	}
}