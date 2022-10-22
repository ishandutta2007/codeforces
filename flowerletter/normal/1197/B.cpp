#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int n,a[MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int i=1;
	while(a[i]<a[i+1] && i<n) i++;
	while(a[i]>a[i+1] && i<n) i++;
	if(i==n) puts("YES");
	else puts("NO");
	return 0;
}