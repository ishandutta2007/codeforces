#include<bits/stdc++.h>
using namespace std;
char s[15];
int a[15],p[15];
int rest(int op,int x)
{
		int st=10-x;
	if(op)
		return st/2;
	return (st+1)/2;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s",s+1);
		for(int i=1;i<=10;++i)
			if(s[i]=='?')	a[i]=-1;
			else	a[i]=s[i]-'0';
			int ans=10;
		for(int i=1;i<=10;++i)	p[i]=a[i];
		for(int i=1;i<=10;i+=2)	if(p[i]==-1)	p[i]=1;
		for(int i=2;i<=10;i+=2)	if(p[i]==-1)	p[i]=0;
		int u=0,v=0;
		for(int i=1;i<=10;++i)
		{
			if(p[i])
			{
				if(i&1)	++v;
				else	++u;
			}
			if(v+rest(1,i)<u)	ans=min(ans,i);
			if(u+rest(0,i)<v)	ans=min(ans,i);
		}
		for(int i=1;i<=10;++i)	p[i]=a[i];
		for(int i=1;i<=10;i+=2)	if(p[i]==-1)	p[i]=0;
		for(int i=2;i<=10;i+=2)	if(p[i]==-1)	p[i]=1;
		u=0,v=0;
		for(int i=1;i<=10;++i)
		{
			if(p[i])
			{
				if(i&1)	++v;
				else	++u;
			}
			if(v+rest(1,i)<u)	ans=min(ans,i);
			if(u+rest(0,i)<v)	ans=min(ans,i);
		}
		printf("%d\n",ans);
	}
	return 0;
}