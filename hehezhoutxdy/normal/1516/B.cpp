// Problem: B. AGAGA XOOORRR
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	int x=0;
    	for(int i=1; i<=n; ++i) a[i]=read(),x^=a[i];
    	if(x) 
    	{
    		int y=a[1];
    		bool f=0;
    		map<int,int> mp;
    		mp[a[1]]=1;
    		for(int j=2; j<n; ++j) 
    		{
    			y^=a[j];
    			mp[y]=1;
    			if(mp[x]&&(y==0)) f=1; 
    		}
    		if(f) puts("YES");
    		else puts("NO");
    	}
    	else puts("YES");
    }
	return 0;
}