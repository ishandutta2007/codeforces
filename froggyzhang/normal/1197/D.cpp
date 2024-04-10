#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 300030
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
int n,m,k,a[N];
ll mn[12],ans;
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=0;i<m;++i)mn[i]=inf;
	mn[0]=0;
	ll s=0;
	for(int i=1;i<=n;++i){
		s+=a[i];
		for(int j=0;j<m;++j){
			ans=max(ans,s-1LL*k*(i/m)-mn[j]-k*(i%m>j));
		}
		mn[i%m]=min(mn[i%m],s-1LL*k*(i/m));
	}
	printf("%lld\n",ans);
	return 0;
}