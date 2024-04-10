#include<bits/stdc++.h>
#define ll long long
#define MX 1000000
#define MD 20
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool b[MX+5];
int n,s[MX/5],cnt,last[MX+5],t[MX+5];
ll num[MX+5][MD+1],K,Ans[MX+5],f[MD+1];
int main()
{
	for(int i=2;i<=MX;++i)
	{
		if(!b[i]) s[++cnt]=i,last[i]=i,t[i]=1e9;
		for(int j=1;s[j]*i<=MX;++j)
		{
			b[s[j]*i]=1,last[s[j]*i]=s[j];
			if(i%s[j]==0) break;
		}
	}
	n=read();ll pp;
	for(int i=1;i<=n;++i) pp=read(),num[pp][1]=read();
	K=read();int R=min(K+1,(long long)MD);
	for(int i=cnt;i;--i)
	{
		int x=s[i];ll l=0,r=-1;
		memset(f,0,sizeof(f));
		for(int j=1;j<=R;++j) if(num[x][j])
		{
			if(r>=j) r+=num[x][j];
			else 
			{
				if(r>=0)
				{
					if(r>K) Ans[x]+=r-K,r=K;
					f[l]=r-l+1;
				}
				l=j;r=j+num[x][j]-1;
			}
		}
		if(r>=0)
		{
			if(r>K) Ans[x]+=r-K,r=K;
			f[l]=r-l+1;
		}
		for(int s=x-1;s>1;)
		{
			int la=last[s],c=0;
			while(s%la==0) s/=la,++c;
			for(int j=1;j<R;++j) num[la][j+1]+=f[j]*c; 
		}
	}
	int an=0;
	for(int i=1;i<=cnt;++i) an+=bool(Ans[s[i]]);
	printf("%d\n",an);
	for(int i=1;i<=cnt;++i) if(Ans[s[i]]) 
		printf("%d %lld\n",s[i],Ans[s[i]]);
	return 0;
}