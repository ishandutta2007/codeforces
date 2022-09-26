#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define N 100010
typedef long long ll;
inline int read(){
	int x=0,f=1;
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
int n,x[N],y[N],p[N],ans[N];
inline ll Dis(ll x,ll y){
	return x*x+y*y;
}
int main(){
//	srand(114514);
	n=read();
	for(int i=1;i<=n;++i){
		x[i]=read(),y[i]=read();
		p[i]=i;
	}
	ll nx=0,ny=0;
//	random_shuffle(p+1,p+n+1);
//	random_shuffle(p+1,p+n+1);
	reverse(p+1,p+n+1);
	for(int t=1;t<=n;++t){
		int i=p[t];
		if(Dis(nx+x[i],ny+y[i])<=Dis(nx-x[i],ny-y[i])){
			nx+=x[i],ny+=y[i];
			ans[i]=1;
		}
		else{
			nx-=x[i],ny-=y[i];
			ans[i]=-1;
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}