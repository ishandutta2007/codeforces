#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int q(int x,int y)
{
	printf("? %d %d\n",x,y),fflush(stdout);
	int t=read();return t;
 } 
signed main()
{
	int n=read();
	int t=q(1,n);
	if(t!=1&&q(1,t)==t)
	{
		int l=1,r=t-1,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(q(mid,t)==t)
			{
				ans=mid,l=mid+1;
			}
			else r=mid-1;
		}
		printf("! %d\n",ans);
	}
	else
	{
		int l=t+1,r=n,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(q(t,mid)==t)
			{
				ans=mid,r=mid-1;
			}
			else l=mid+1;
		}
		printf("! %d\n",ans);
	}
	return 0;
}