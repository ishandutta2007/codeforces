// Problem: E. Colors and Intervals
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],lst[103];
int ansl[103],ansr[103];
bool vis[103];
#define lans ansl
#define rans ansr
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n*m; ++i)
		a[i]=read();
	for(int l=1,r=m-1; l<=n; l+=m-1,r+=m-1)
	{
		r=min(r,n);
		for(int i=1; i<=n*m; ++i) 
		{
			if(l<=a[i]&&a[i]<=r&&!vis[a[i]]) 
			{
				if(lst[a[i]])
				{
					lans[a[i]]=lst[a[i]],rans[a[i]]=i;
					vis[a[i]]=1;
					for(int j=l; j<=r; ++j) lst[j]=0;
				}
				else lst[a[i]]=i;
			}
		}
	}
	for(int i=1; i<=n; ++i) printf("%d %d\n",ansl[i],ansr[i]);
	return 0;
}