#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int n,m,a[N],las[N],ans,pre[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		pre[i]=m+1;
	}
	for(int i=1;i<=m;++i){
		a[i]=read();
		las[a[i]]=i;
		pre[a[i]]=min(pre[a[i]],i);
	}
	for(int i=1;i<=n;++i){
		if(i>1&&las[i-1]<pre[i])++ans;
		if(pre[i]==m+1)++ans;
		if(i<n&&las[i+1]<pre[i])++ans;
	}
	printf("%d\n",ans);
	return 0;
}