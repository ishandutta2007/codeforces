#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,c[MN+5];
int F[MN+5][MN+5];
int main()
{
	n=read();
	memset(F,63,sizeof(F));
	for(int i=1;i<=n;++i) c[i]=read(),F[i][i]=1;
	for(int l=2;l<=n;++l)
	{
		for(int i=1;i+l-1<=n;++i)
		{
			int j=i+l-1;
			if(c[i]==c[j]) 
			{
				if(i+1==j) F[i][j]=1;
				else F[i][j]=min(F[i][j],F[i+1][j-1]);	
			}
			for(int k=i;k<j;++k) F[i][j]=min(F[i][j],F[i][k]+F[k+1][j]);
		//	cout<<i<<" "<<j<<" "<<F[i][j]<<endl;
		}
	}
	printf("%d\n",F[1][n]);
	return 0;
}