#include<bits/stdc++.h>
using namespace std;
#define N 2333
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
int n,a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	if(n==1)puts("NO");
	else printf("%d\n",a[2]);
	return 0;
}