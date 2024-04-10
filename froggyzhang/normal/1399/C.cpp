#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 233
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
int T,n,a[N];
int Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int s=2;s<=(n<<1);++s){
		int tot=0;
		int l=1,r=n;
		while(l<r){
			if(a[l]+a[r]==s){
				++tot,++l,--r;
				continue;
			}
			if(a[l]+a[r]<s)++l;
			else --r;
		}
		ans=max(ans,tot);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}