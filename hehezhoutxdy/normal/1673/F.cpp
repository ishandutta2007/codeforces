// Problem: F. Anti-Theft Road Planning
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int pre[]={0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8,24,25,27,26,30,31,29,28,20,21,23,22,18,19,17,16};
const int low[]={1,2,1,4,1,2,1,8,1,2,1,4,1,2,1,16,1,2,1,4,1,2,1,8,1,2,1,4,1,2,1};
signed main()
{
	int n=read(),T=read(),s=0;
	for(int i=0; i<n; ++i,puts(""))
		for(int j=0; j+1<n; ++j)
			printf("%d ",low[j]*low[j]),s+=low[j]*low[j];
	for(int i=0; i+1<n; ++i,puts(""))
		for(int j=0; j<n; ++j)
			printf("%d ",low[i]*low[i]*2),s+=low[i]*low[i]*2;
	fflush(stdout);
	int px=0,py=0;
	while(T--)
	{
		int x=read(),cx=0,cy=0;
		for(int i=0; i<20; ++i) 
			if(i&1) cx|=((x>>i)&1)<<(i>>1);
			else cy|=((x>>i)&1)<<(i>>1);
		for(int i=0; i<32; ++i) 
			if((pre[px]^pre[i])==cx)
				{px=i;break;}
		for(int i=0; i<32; ++i) 
			if((pre[py]^pre[i])==cy)
				{py=i;break;}	
		printf("%d %d\n",px+1,py+1),fflush(stdout);
	}
	cerr<<s<<endl;
	return 0;
}