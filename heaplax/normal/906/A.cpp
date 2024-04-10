#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,shock,ans=-1;
char s[100001];
bool ok[26],fin[26];
int main()
{
	for(int i=0;i<26;++i)ok[i]=1;
	int t;re(t);
	while(t--)
	{
		int opt;re(opt);
		scanf("%s",s);
		n=strlen(s);
		if(opt=='.'-48)
		{
			for(int i=0;i<n;++i)
				ok[s[i]-'a']=0;
			if(!~ans)
			{
				int one=0;
				for(int i=0;i<26;++i)
					one+=ok[i];
				if(one==1)ans=shock;	
			}	
		}
		else if(opt=='!'-48)
		{
			++shock;
			memset(fin,0,sizeof fin);
			for(int i=0;i<n;++i)
				fin[s[i]-'a']=1;
			for(int i=0;i<26;++i)
				ok[i]&=fin[i];
			if(!~ans)
			{
				int one=0;
				for(int i=0;i<26;++i)
					one+=ok[i];
				if(one==1)ans=shock;	
			}	
		}
		else 
		{
			if(t)
			{
				++shock;
				ok[s[0]-'a']=0;
				if(!~ans)
				{
					int one=0;
					for(int i=0;i<26;++i)
						one+=ok[i];
					if(one==1)ans=shock;	
				}	
			}
			else if(!~ans)ans=shock;
		}
	}
	printf("%d\n",shock-ans);
}