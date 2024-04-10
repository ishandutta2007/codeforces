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
struct node
{
	int a,id;
	bool operator<(const node&w)const{return a<w.a;}
}e[xx];
int ans[xx];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
		{
			e[i].a=read();
			e[i].id=i;
		}
		sort(e+1,e+n+1);
		if(n&1)
		{
			for(int i=1;i<=n-3;i++)
			{
				if(i&1)
				{
					if(e[i].a==e[i+1].a)
					ans[e[i].id]=-1;
					else ans[e[i].id]=-e[i+1].a;
				}
				else 
				{
					if(e[i].a==e[i-1].a)
					ans[e[i].id]=1;
					else ans[e[i].id]=e[i-1].a;
				}
			}
			if(e[n-1].a+e[n-2].a)
			{
				ans[e[n].id]=-e[n-1].a-e[n-2].a;
				ans[e[n-1].id]=ans[e[n-2].id]=e[n].a;
			}
			else 
			{
//			puts("SSS");
				ans[e[n-2].id]=-e[n].a-e[n-1].a;
				ans[e[n-1].id]=ans[e[n].id]=e[n-2].a;
//			cout<<ans[e[n].id]<<" "<<e[n].id<<" "<<e[]<<"\n";
			}
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				if(i&1)
				{
					if(e[i].a==e[i+1].a)
					ans[e[i].id]=-1;
					else ans[e[i].id]=-e[i+1].a;
				}
				else 
				{
					if(e[i].a==e[i-1].a)
					ans[e[i].id]=1;
					else ans[e[i].id]=e[i-1].a;
				}
			}
		}
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}