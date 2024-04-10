#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,m,a[N];
ll ans;
map<int,int> l,r;
int main(){
	n=read(),m=read();
	if(n==1){puts("0");return 0;}
	for(int i=1;i<=m;++i){
		a[i]=read();
	}
	for(int i=m;i>=1;--i){
		r[a[i]-i]=r[a[i]-i-1]+1;
		l[a[i]+i]=l[a[i]+i+1]+1;
	}
	for(int i=1;i<=n;++i){
		int L=max(1,i-m-1+l[i]);
		int R=min(n,i+m+1-r[i]);
		ans+=R-L+1;
	}
	printf("%lld\n",ans);
	return 0;
}