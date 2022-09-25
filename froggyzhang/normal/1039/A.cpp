#include<bits/stdc++.h>
using namespace std;
#define N 200002
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
int n,s[N],t[N];
ll T,a[N],b[N];
int main(){
	n=read(),T=read();
	for(int i=1;i<=n;++i){
		a[i]=read()+T;
	}
	for(int i=1;i<=n;++i){
		int x=read();
		if(x<i)return !printf("No\n");	
		t[x+1]=1;
		++s[i+1],--s[x+1];
	}
	for(int i=1;i<=n;++i){
		s[i]+=s[i-1];
	}
	ll now=0;
	for(int i=1;i<=n;++i){
		++now;
		if(i<n&&s[i+1]){
			now=max(now,a[i+1]);
		}
		else{
			now=max(now,a[i]);
		}
		b[i]=now;
		if(i<n&&now>=a[i+1]&&t[i+1])return !printf("No\n");
	}
	printf("Yes\n");
	for(int i=1;i<=n;++i)printf("%lld ",b[i]);	
	return 0;
}