#include<bits/stdc++.h>
#define MN 50
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5][MN+5];
int n,s[MN+5],size[MN+5],num,b[25],q[MN+5],f[1<<23],Num[1<<23],F[1<<23];
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
void Merge(int x,int y)
{
	if(getfa(x)!=getfa(y)) 
		size[getfa(y)]+=size[getfa(x)],s[getfa(x)]=getfa(y);
}
vector<int> v[MN+5];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) size[i]=1,scanf("%s",st[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) 
		if(st[i][j]=='A') Merge(i,j);
	for(int i=1;i<=n;++i) v[getfa(i)].push_back(i);
	for(int i=1;i<=n;++i)
		for(int j=0;j<v[i].size();++j)
			for(int k=j+1;k<v[i].size();++k)
				if(st[v[i][j]][v[i][k]]=='X')
					return 0*puts("-1");
	for(int i=1;i<=n;++i) if(getfa(i)==i)
		if(size[i]>1)
		{
			q[++num]=i;
			for(int j=1;j<num;++j)
				for(int l=0;l<v[q[j]].size();++l)
					for(int r=0;r<v[i].size();++r)
						if(st[v[q[j]][l]][v[i][r]]=='X')
						 	b[num]|=1<<j-1,b[j]|=1<<num-1;
		}
	for(int i=0;i<1<<num;++i) f[i]=1;
	for(int i=1;i<1<<num;++i)
	{
		Num[i]=Num[i>>1]+(i&1);
		for(int j=0;j<num;++j) 
			if(i&(1<<j)&&(b[j+1]&i)) f[i]=0;
	}
	if(!num||f[(1<<num)-1]) return 0*printf("%d\n",n-(!num));
	for(int i=0;i<num;++i) for(int j=0;j<1<<num;++j)
		if(j&(1<<i)) f[j]+=f[j^(1<<i)];
	for(int i=0;i<1<<num;++i) F[i]=f[i];
	for(int k=1;;++k)
	{
		int res=0;
		for(int j=0;j<1<<num;++j) 
		{
			F[j]=1LL*F[j]*f[j]%mod;
			if((num-Num[j])&1) res=(res+mod-F[j])%mod;
			else res=(res+F[j])%mod;
		}
		if(res) return 0*printf("%d\n",n+k);
	}
	return 0;
}