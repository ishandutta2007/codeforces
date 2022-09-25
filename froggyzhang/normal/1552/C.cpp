#include<bits/stdc++.h>
using namespace std;
#define N 233
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
int s[N],a[N],n,m,T,x[N],y[N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n<<1;++i)a[i]=1;
	for(int i=1;i<=m;++i){
		x[i]=read(),y[i]=read();
		if(x[i]>y[i])swap(x[i],y[i]);
		a[x[i]]=a[y[i]]=0;
	}
	for(int i=1;i<=n<<1;++i){
		s[i]=s[i-1]+a[i];
	}
	int ans=(n-m)*(n-m-1)/2;
	for(int i=1;i<=m;++i){
		int t=s[y[i]]-s[x[i]];
		ans+=min(t,(n<<1)-(m<<1)-t);
	}
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			ans+=(x[i]>x[j]&&x[i]<y[j])^(y[i]>x[j]&&y[i]<y[j]);
		}	
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}