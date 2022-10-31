#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
typedef long long ll;
int a[N],b[N],Log2[N];
ll s[N],f[N][20],g[N][20];
inline ll ask1(int l,int r){
	int k=Log2[r-l+1];
	return std::max(f[l][k],f[r-(1<<k)+1][k]);
}
inline ll ask2(int l,int r){
	int k=Log2[r-l+1];
	return std::min(g[l][k],g[r-(1<<k)+1][k]);
}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+b[i]-a[i];
	for(int i=n;i>=1;--i){f[i][0]=s[i];for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)f[i][j]=std::max(f[i][j-1],f[i+(1<<(j-1))][j-1]);}
	for(int i=n;i>=1;--i){g[i][0]=s[i];for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)g[i][j]=std::min(g[i][j-1],g[i+(1<<(j-1))][j-1]);}
	while(q--){
		int l,r;read(l,r);
		printf("%lld\n",s[r]!=s[l-1]||ask2(l,r)-s[l-1]<0?-1LL:ask1(l,r)-s[l-1]);
	}
	return 0;
}