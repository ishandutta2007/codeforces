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
int a[10003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1; i<=n; i++) a[i]=read();
		bool f=1;
		for(int i=1; i<=n; i++)
		{
			if(a[i]<i-1)
			{
				f=0;
				break;	
			}
			int t=a[i]-(i-1);
			a[i+1]+=t;
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}