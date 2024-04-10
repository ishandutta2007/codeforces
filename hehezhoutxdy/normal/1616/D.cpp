// Problem: D. Keep the Average High
// Contest: Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],stk[1000003];
pair<int,int> b[1000003];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int x=read();
		for(int i=1; i<=n; ++i) a[i]-=x;
		for(int i=1; i<=n; ++i) a[i]+=a[i-1];
		int top=0,len=0;
		for(int i=1; i<=n; ++i)
		{
        	int l=1,r=top,res=0;
	        while(l<=r)
	        {
	            int mid=(l+r)>>1;
	            if(cmp(stk[mid],i)) res=mid,l=mid+1;
	            else r=mid-1;
	        }
	        (res)&&(b[++len]=make_pair(i,stk[res]+1),0);
	        while(top&&!cmp(stk[top],i-1)) --top;
	        stk[++top]=i-1;
	    }
	    int lst=-1e18,ans=n;
	    for(int i=1; i<=len; ++i) if(lst<b[i].second) 
	    	lst=b[i].first,--ans;
	    printf("%lld\n",ans);
	}
	return 0;
}