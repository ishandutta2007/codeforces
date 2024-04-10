// Problem: E. Minimax
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[53];
char s[100003];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		for(int i=0; i<26; ++i) a[i]=0;
		int n=strlen(s+1);
		for(int i=1; i<=n; ++i) ++a[s[i]-'a'];
		int cnt=0;
		for(int i=0; i<26; ++i) cnt+=(a[i]>0);
		if(cnt==1)
		{
			for(int i=0; i<26; ++i)
				for(int j=1; j<=a[i]; ++j)
					printf("%c",'a'+i);
			puts("");
			continue;
		}
		bool F=0;
		for(int i=0; i<26; ++i) if(a[i]==1)
		{
			for(int j=1; j<=a[i]; ++j) printf("%c",'a'+i);
			a[i]=0;
			for(int ii=0; ii<26; ++ii)
				for(int j=1; j<=a[ii]; ++j)
					printf("%c",'a'+ii);
			puts("");
			F=1;
			break;
		}
		if(F) continue;
		int fir=-1,sec=-1;
		for(int i=0; i<26; ++i) if(a[i]){fir=i;break;}
		//case 1 
		int N=n-a[fir];
		if(a[fir]-2<=N)//
		{
			queue<int> q;
			for(int i=fir+1; i<26; ++i) 
			for(int j=1; j<=a[i]; ++j) q.push(i);
			printf("%c",'a'+fir);
			--a[fir];
			for(;a[fir]--;)
			{if(q.empty()) printf("%c",'a'+fir); else {printf("%c%c",'a'+fir,'a'+q.front()),q.pop();}}
			while(!q.empty()){printf("%c",'a'+q.front()),q.pop();} 
			puts("");
		}
		else if(cnt==2)
		{
			for(int j=fir+1; j<26; ++j) if(a[j]){sec=j;break;}
			printf("%c",'a'+fir);
			for(int j=1; j<=a[sec]; ++j) printf("%c",'a'+sec);
			for(int j=1; j<a[fir]; ++j) printf("%c",'a'+fir);
			puts("");
		}
		else
		{
			for(int j=fir+1; j<26; ++j) if(a[j]){sec=j;break;}
			printf("%c%c",'a'+fir,'a'+sec),--a[sec];
			
			for(int j=1; j<a[fir]; ++j) printf("%c",'a'+fir);
			
			for(int j=sec+1; j<26; ++j) if(a[j])
			{
				printf("%c",'a'+j);
				--a[j];
				break;
			}
		
			for(int ii=sec; ii<26; ++ii)
				for(int j=1; j<=a[ii]; ++j)
					printf("%c",'a'+ii);
			puts("");
		}
	}
	return 0;
}