#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],b[100003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1; i<=n; i++) a[i]=read(),b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int x=n>>1;
		if(n&1) puts("1");
		else printf("%lld\n",(a[x+1]-a[x]+1)*(b[x+1]-b[x]+1));
	}
	return 0;
}