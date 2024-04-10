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
int a[1000003];
int b[1000003];
int c[1000003];
int d[1000003];
signed main()
{
	int n=read(),k=read();
	for(int i=1; i<=n; i++) a[i]=read();
	int l=1,r=n,ans=1;b[0]=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		for(int i=1; i<=n; i++) b[i]=(a[i]>=mid);
		int f=0;
		for(int i=1; i<=n; i++) c[i]=c[i-1]+(b[i]?1:-1);
		for(int i=1; i<=n; i++) d[i]=min(d[i-1],c[i]);
		for(int i=k; i<=n; i++) 
				if(c[i]-d[i-k]>0) 
				{
					f=1;
					break;
				}
		if(f) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}