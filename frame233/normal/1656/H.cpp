#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=1005,NC=2049;typedef __int128 LL;
void print(const LL &x){if(x>9)print(x/10);putchar(x%10+48);}
LL a[N],b[N];
struct seg{
	LL X,v[NC];int M;
	void build(int n,LL V,LL *arr){
		X=V;for(M=1;M<=n+2;M<<=1);
		memset(v,0,M*2*sizeof(LL));
		for(int i=1;i<=n;++i)v[i+M]=X/gcd(X,arr[i]);
		for(int i=M-1;i>=1;--i)v[i]=gcd(v[i<<1],v[i<<1|1]);
	}
	void upd(int x){for(v[x+=M]=0,x>>=1;x;x>>=1)v[x]=gcd(v[x<<1],v[x<<1|1]);}
}tr1[N],tr2[N];
bool A[N],B[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]),A[i]=1;
	for(int i=1;i<=m;++i)read(b[i]),B[i]=1;
	for(int i=1;i<=n;++i)tr1[i].build(m,a[i],b);
	for(int i=1;i<=m;++i)tr2[i].build(n,b[i],a);
	while(true){
		bool flag=0;
		for(int i=1;i<=n;++i)if(A[i]&&tr1[i].v[1]>1){flag=1,A[i]=0;for(int j=1;j<=m;++j)if(B[j])tr2[j].upd(i);}
		for(int i=1;i<=m;++i)if(B[i]&&tr2[i].v[1]>1){flag=1,B[i]=0;for(int j=1;j<=n;++j)if(A[j])tr1[j].upd(i);}
		if(!flag)break;
	}
	std::vector<LL> v1,v2;
	for(int i=1;i<=n;++i)if(A[i])v1.pb(a[i]);
	for(int i=1;i<=m;++i)if(B[i])v2.pb(b[i]);
	if(v1.empty()||v2.empty())puts("NO");
	else{
		printf("YES\n%d %d\n",SZ(v1),SZ(v2));
		for(auto it:v1)print(it),putchar(' ');
		puts("");
		for(auto it:v2)print(it),putchar(' ');
		puts("");
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}