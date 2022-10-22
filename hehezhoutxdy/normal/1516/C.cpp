// Problem: C. Baby Ehab Partitions Again
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
bitset<200001> bs;
int a[103];
signed main()
{
    int n=read();
    bs[0]=1;
    int s=0;
    for(int i=1; i<=n; ++i) a[i]=read(),s+=a[i];
    for(int i=1; i<=n; ++i) bs=bs|(bs<<a[i]);
	if(s&1)
	{
		puts("0");
		return 0;
	}
	if(!bs[s/2]) 
	{
		puts("0");
		return 0;
	}
	for(int Y=1; Y<=n; ++Y)
	{
		int T=s-a[Y];		
		if(T&1)
		{
			puts("1");
			printf("%lld\n",Y);
			return 0;
		}
		bs.reset();
		bs[0]=1;
		for(int i=1; i<=n; ++i) 
		if(i!=Y)bs=bs|(bs<<a[i]);
		if(!bs[T/2])
		{
			puts("1");
			printf("%lld\n",Y);
			return 0;
		}
	}
	return 0;
}