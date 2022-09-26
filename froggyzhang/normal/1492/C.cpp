#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,m,pre[N],suf[N],ans;
char a[N],b[N];
int main(){
	n=read(),m=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(int j=1,i=1;j<=m;++j){
		while(i<=n&&a[i]^b[j])++i;
		pre[j]=i;
		++i;
	}
	for(int j=m,i=n;j>=1;--j){
		while(i>=1&&a[i]^b[j])--i;
		suf[j]=i;
		--i;
	}
	for(int i=1;i<=m-1;++i){
		ans=max(ans,suf[i+1]-pre[i]);
	}
	printf("%d\n",ans);
	return 0;
}