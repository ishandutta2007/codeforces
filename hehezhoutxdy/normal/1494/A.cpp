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
char s[1000003];
int a[1000003];
signed main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		bool f=0;
		int n=strlen(s+1);
		for(int i=0; i<=7; i++)
		{
			for(int j=1; j<=n; j++)if(s[j]=='A')
			{
				a[j]=(i&1);	
			}else if(s[j]=='B')
			a[j]=i&2;
			else a[j]=i&4;
			int C=0;
			for(int j=1; j<=n; j++)
			{
				if(a[j]) ++C;
				else --C;
				if(C<0)
				{
					break;
				}
			}
			if(C==0)
			{
				f=1;
				break;
			}
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}