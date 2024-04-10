// Problem: D. Backspace
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
char s[1000003],t[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		int n=strlen(s+1),m=strlen(t+1);
		int pos=1,C=0;
		int i;
		for(i=1; i<=n; i++) 
		if(pos<=m&&t[pos]==s[i]) ++pos,C=0;
		else i++,++C;
		if(pos>m&&(i==n+1)) {puts("YES");continue;}
		pos=1;C=0;
		for(i=2; i<=n; i++) 
		if(pos<=m&&t[pos]==s[i]) ++pos,C=0;
		else i++,++C;
		if(pos>m&&(i==n+1)) {puts("YES");continue;}
		puts("NO");
	}
	return 0;
}