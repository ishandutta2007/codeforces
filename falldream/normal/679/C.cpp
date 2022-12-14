#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 500
#define num(x,y) ((x-1)*n+y)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,k,s[MN*MN+5],size[MN*MN+5],num[MN*MN+5],tot=0,ans=0,p[MN+5][MN+5];char st[MN+5][MN+5];
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
void Merge(int x,int y){if(getfa(x)!=getfa(y)) size[getfa(y)]+=size[getfa(x)],s[getfa(x)]=getfa(y);}
void Add(int x) {if(!num[x]++) tot+=size[x];}
void Del(int x) {if(!--num[x]) tot-=size[x];}
inline bool Ok(int x,int y){return x>0&&y>0&&x<=n&&y<=n&&st[x][y]=='.';}
inline int Calc(int x,int X,int y,int Y){return p[X][Y]-p[x-1][Y]-p[X][y-1]+p[x-1][y-1];}
int main()
{	
	n=read();k=read();
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) 
		size[num(i,j)]=st[i][j]=='.',
		p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+(st[i][j]=='.');
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(st[i][j]=='.')
		for(int k=0;k<4;++k)
		{
			int x=i+dis[k][0],y=j+dis[k][1];
			if(!Ok(x,y)) continue;
			Merge(num(x,y),num(i,j));	
		}
	for(int i=1;i+k-1<=n;++i)
	{
		memset(num,0,sizeof(num));tot=0;
		for(int j=i-1;j<=i+k;++j) 
			for(int l=1;l<=k+1;++l) if(Ok(j,l))
			{
				if(l==k+1&&(j==i-1||j==i+k)) continue;
			 	Add(getfa(num(j,l)));
			}
		ans=max(ans,tot+k*k-Calc(i,i+k-1,1,k));
		for(int l=2;l+k-1<=n;++l)
		{
			for(int j=i;j<=i+k-1;++j)
			{
				if(Ok(j,l-2)) Del(getfa(num(j,l-2)));
				if(Ok(j,l+k)) Add(getfa(num(j,l+k)));
			}
			if(Ok(i-1,l-1)) Del(getfa(num(i-1,l-1)));
			if(Ok(i+k,l-1)) Del(getfa(num(i+k,l-1)));
			if(Ok(i-1,l+k-1)) Add(getfa(num(i-1,l+k-1)));
			if(Ok(i+k,l+k-1)) Add(getfa(num(i+k,l+k-1)));
			ans=max(ans,tot+k*k-Calc(i,i+k-1,l,l+k-1));
		}
	}		
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(st[i][j]=='.') ans=max(ans,size[getfa(num(i,j))]);
	printf("%d\n",ans);
	return 0;
}