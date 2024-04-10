#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 3e5+10;
int n,k,a[MAXN],b[MAXN],ans;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	ans=a[n]-a[1];
	for(int i=1;i<n;i++) b[i]=-a[i+1]+a[i];
	sort(b+1,b+n);
	for(int i=1;i<k;i++) ans+=b[i];
	cout<<ans;
	return 0;
}