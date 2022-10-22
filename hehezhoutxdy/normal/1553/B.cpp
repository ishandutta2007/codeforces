// Problem: B. Reverse String
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
char s[1000003];
char t[1000003];
bool f1[1003][1003],f2[1003][1003];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		int n=strlen(s+1),m=strlen(t+1);
		for(int j=0; j<=n+1; ++j)
		{
		for(int i=0; i<=m+1; ++i)
			f1[j][i]=f2[j][i]=0;
		}
		for(int i=1; i<=n; ++i)
		//string s start from i
			for(int j=1; j<=m; ++j)
			//string t start from j
				if(m-j+1<=i)
				{
					bool flg=1;
					for(int s1=i,s2=j; s2<=m; --s1,++s2)
					{
						assert(s1>=1);
						if(s[s1]!=t[s2])
						{
							flg=0;
							break;
						}
					}
					if(flg)f2[i][j]=1;
				}
		bool FF=0;
		for(int i=1; i<=n; ++i)
		//string s start from i
			for(int j=1; j<=m; ++j)
			//string t start from j
				if(j<=i)
				{
					bool flg=1;
					for(int s1=i,s2=j; s2>=1; --s1,--s2)
					{
						assert(s1>=1);
						if(s[s1]!=t[s2])
						{
							flg=0;
							break;
						}
					}
					if(flg) f1[i][j]=1;
				}
		for(int j=1; j<=m; ++j)
			for(int i=1; i<=n; ++i)
				if((f1[i][j])&&(f2[i][j])) 
					FF=1;
		if(FF) puts("YES");
		else puts("NO"); 
	}
	return 0;
}