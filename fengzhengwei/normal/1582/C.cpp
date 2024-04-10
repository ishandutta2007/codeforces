#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
char s[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		int ans=1e9;
		for(int i=0;i<26;i++)
		{
			int l=1,r=n,vs=1;
			int num=0;
			while(l<=r)
			{
				if(s[l]==s[r])
				{
					l++,r--;
					continue;
				}
				if(s[l]!=s[r])
				{
					if(s[l]=='a'+i)
					{
						l++;num++;
						continue;
					}
					if(s[r]=='a'+i)
					{
						r--;
						num++;
						continue;
					}
					vs=0;
					break;
				}
			}
			if(vs)
			{
				ans=min(ans,num);
			}
		}
		if(ans==1e9)
		{
			puts("-1");
		}
		else cout<<ans<<"\n";
	}
	return 0;
}