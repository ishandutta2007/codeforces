#include<bits/stdc++.h>
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
int n,m,a[N],b[N],ans;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	a[++n]=1e9;
	sort(a+1,a+n+1);
	int len=0;
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),y=read();
		if(l==1)b[++len]=r;	
	}
	sort(b+1,b+len+1);
	ans=n+m;
	for(int i=1,j=1;i<=n;++i){
		while(j<=len&&b[j]<a[i])++j;
		ans=min(ans,len-j+1+i-1);
	}
	printf("%d\n",ans);
	return 0;
}