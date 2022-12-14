#include<bits/stdc++.h>
#define MX 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<int,int> mp,mp2;
int a,b,mod,top,q[MX+5],step[MX+5];
inline int pow(int x,int k)
{
	int res=1;
	for(;k;k>>=1,x=1LL*x*x%mod)if(k&1)res=1LL*res*x%mod;
	return res;	
}
void Add(int x,int way,int s)
{
	if(mp[x]) return;mp[x]=way;
	if(top<MX) q[++top]=x,step[top]=s;
}
int Ans[105],Ans2[105],ans,ans2;
void Try(int x,int way,int s)
{
	if(mp2[x]) return;mp2[x]=way;
	if(mp[x])
	{
		for(int i=x;i!=a;)
		{
			Ans[++ans]=mp[i];
			if(Ans[ans]==3) i=pow(i,mod-2);
			else i=(i+(Ans[ans]<2?mod-1:1))%mod;	
		}
		for(int i=x;i!=b;)
		{
			Ans2[++ans2]=mp2[i];
			if(Ans2[ans2]==3) i=pow(i,mod-2);
			else Ans2[ans2]^=3,i=(i+(Ans2[ans2]<2?1:mod-1))%mod;	
		}
		printf("%d\n",ans+ans2);
		for(int j=ans;j;--j)printf("%d ",Ans[j]);
		for(int j=1;j<=ans2;++j)printf("%d ",Ans2[j]);
		exit(0);	
	}
	if(top<MX) q[++top]=x,step[top]=s;
}
int main()
{
	a=read();b=read();mod=read();Add(a,0,0);
	for(int i=1;i<=top;++i)
	{
		int x=q[i];if(step[i]>=100) continue;
		Add((x+1)%mod,1,step[i]+1);
		Add((x+mod-1)%mod,2,step[i]+1);
		Add(pow(x,mod-2),3,step[i]+1);	
	}
	top=0;Try(b,0,0);
	for(int i=1;i<=top;++i) 
	{
		int x=q[i];if(step[i]>=100) continue;
		Try((x+1)%mod,1,step[i]+1);
		Try((x+mod-1)%mod,2,step[i]+1);
		Try(pow(x,mod-2),3,step[i]+1);	
	}
	return 0;
}