#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int a[200005],ans[200005];
bool vis[200005],mtc[200005];
int main(){
	int T=read();
	while(T-->0)
	{
		int n=read();
		for(int i=1;i<=n;++i)	a[i]=read();
		for(int i=1;i<=n;++i)	vis[i]=mtc[i]=false,ans[i]=0;
		int ret=0;
		for(int i=1;i<=n;++i)
		{
			if(!vis[a[i]])	vis[a[i]]=mtc[i]=true,++ret,ans[i]=a[i];
		}
		write(ret),puts("");
		vector<int> st;
		for(int i=1;i<=n;++i)	if(!vis[i])	st.push_back(i);
//		sort(st.begin(),st.end());
		reverse(st.begin(),st.end());
//		int pos=1;
		for(int i=1;i<=n;++i)
		{
			if(!ans[i])
			{
				ans[i]=st.back();
				st.pop_back();
//				while(vis[pos])	++pos;
//				ans[i]=pos++;
			}
		}
		int las=0;
		for(int i=1;i<=n;++i)
		{
			if(ans[i]==i)
			{
				if(!las)	las=i;
				else	swap(ans[i],ans[las]);
			}
		}
		if(las)
		{
			for(int i=1;i<=n;++i)
			{
				if(a[i]==a[las])
				{
					swap(ans[i],ans[las]);
					break;
				}
			}
		}
		for(int i=1;i<=n;++i)	write(ans[i]),putchar(' ');
		puts("");
	}
	return 0;
}