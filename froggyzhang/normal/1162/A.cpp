#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int n,h,m,a[N],ans;
int main(){
	n=read(),h=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=h;
	}
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),x=read();
		for(int j=l;j<=r;++j){
			a[j]=min(a[j],x);
		}
	}
	for(int i=1;i<=n;++i){
		ans+=a[i]*a[i];
	}
	printf("%d\n",ans);
	return 0;
}