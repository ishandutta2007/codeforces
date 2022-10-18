#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
const int mod=998244353;
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
int n,m,a[N],b[N];
int ans;
int main(){
	n=read(),m=read();
	if(n<m){
		printf("0\n");return 0;
	}
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	int pos=n+1;
	ans=1;
	for(int i=m;i>=1;--i){
		int d=-1;
		while(pos>1&&a[pos-1]>=b[i]){
			--pos;
			if(a[pos]==b[i])d=max(d,pos);
		}
		if(d==-1){
			printf("0\n");
			return 0;
		}
		if(i^1)ans=1LL*ans*(d-pos+1)%mod;
	}
	if(pos>1){
		printf("0\n");return 0;
	}
	cout<<ans<<endl;
	return 0;
}