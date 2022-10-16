#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,L,R,a[N],b[N];
void Solve(){
	n=read(),L=read(),R=read();
	for(int i=1;i<=n;++i)a[i]=b[i]=0;
	for(int i=1;i<=L;++i)++a[read()];
	for(int i=1;i<=R;++i)++b[read()];
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=min(a[i],b[i]);
		L-=x,R-=x;
		a[i]-=x,b[i]-=x;
	}
	for(int i=1;i<=n;++i){
		while(a[i]>=2&&L>=R+2)L-=2,a[i]-=2,++ans;
		while(b[i]>=2&&R>=L+2)R-=2,b[i]-=2,++ans;
	}
	ans+=max(L,R);
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}