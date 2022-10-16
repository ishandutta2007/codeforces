#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
char c[105];
char s[105];
int x,y;
int f[1005];
signed main(){
	n=read();
	m=read();
	scanf("%s",c+1);
	scanf("%s",s+1);
	c[0]=']';
	s[0]='-';
	x=strlen(c)-1;
	y=strlen(s)-1;
	for(int i=0;i<y;i++)
	{
		int now=i+1;
		int res=0;
		for(int j=1;j<=x;j++)
		{
			if(c[j]==s[now])
			{
				now++;res++;
				if(now>y)now-=y;
			}
		}
		f[i]=res;
	}
	int now=0;
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=f[now];
		now+=f[now];
		now%=y;
	}
	cout<<res/y/m<<endl;
	return 0;
}