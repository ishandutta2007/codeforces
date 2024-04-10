#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define N 400040
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,pw2[N],n,a[N],b[N],pa[N],pb[N];
struct Union_Set{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i;	
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	inline int Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return 0;
		f[fy]=fx;
		return 1;
	}
}S;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i){
		pa[a[i]]=i;
		pb[b[i]]=i;
	}
	int ans=n;
	S.init(n);
	for(int i=1;i<=n;++i){
		ans-=S.Merge(pb[a[i]],i);
		ans-=S.Merge(pa[b[i]],i);
	}
	printf("%d\n",pw2[ans]);
}
int main(){
	pw2[0]=1;
	for(int i=1;i<=400000;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}