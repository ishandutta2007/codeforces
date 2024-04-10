#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 300030
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
int n,m,a[N],b[N],ans;
int main(){
	n=read(),m=read()-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=2;i<=n;++i){
		b[i-1]=a[i]-a[i-1];
	}
	sort(b+1,b+n,greater<int>());
	ans=a[n]-a[1];
	for(int i=1;i<=m;++i){
		ans-=b[i];
	}
	printf("%d\n",ans);
	return 0;
}