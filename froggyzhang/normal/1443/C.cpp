#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
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
int T,n,a[N],b[N],p[N];
int Solve(){
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	int ans=a[p[n]];
	for(int i=n,sum=0;i>=1;--i){
		sum+=b[p[i]];
		ans=min(ans,max(sum,a[p[i-1]]));
		if(sum>a[p[i-1]])break;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			b[i]=read();
		}
		printf("%d\n",Solve());
	}
	return 0;
}