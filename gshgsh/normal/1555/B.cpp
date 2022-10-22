#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	int T=get();
	while(T--)
	{
		int W=get(),H=get(),x1=get(),y1=get(),x2=get(),y2=get(),w=get(),h=get();
		if(x2-x1+w>W&&y2-y1+h>H){cout<<"-1\n";continue;}
		int ans=min(x2-x1+w<=W?min(max(w-x1,0),max(w-W+x2,0)):1e9,y2-y1+h<=H?min(max(h-y1,0),max(h-H+y2,0)):1e9);cout<<ans<<'\n';
	}
	return 0;
}