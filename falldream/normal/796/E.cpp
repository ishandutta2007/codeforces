#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 30000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,p,k,m;
short f[2][1003][53][53];
bool s[2][1003];

inline void R(short&x,short y){if(y>x)x=y;}

int main()
{
	memset(f,128,sizeof(f));
	n=read();p=read();k=read();
	m=read();for(int i=1;i<=m;i++) s[0][read()]=1;
	m=read();for(int i=1;i<=m;i++) s[1][read()]=1;
	if(p>=(n+k-1)/k*2) 
	{
		int ans=0;
		for(int i=1;i<=n;i++) ans+=s[0][i]|s[1][i];
		return 0*printf("%d\n",ans);
	} 
//	for(int i=1;i<=n;i++) s[0][i]+=s[0][i-1],s[1][i]+=s[1][i-1];
	f[0][0][0][0]=0;
	for(int i=0,now=1,pre=0;i<n;i++,now^=1,pre^=1)
	{
		for(int j=0;j<=p;j++)	
		{			 
			for(int x=0;x<=k;x++)
				for(int y=0;y<=k;y++)
				{
					if(!x&&!y) 
					{
						R(f[now][j][0][0],f[pre][j][0][0]);
						R(f[now][j+1][0][k-1],f[pre][j][0][0]+s[1][i+1]);
						R(f[now][j+1][k-1][0],f[pre][j][0][0]+s[0][i+1]);
						R(f[now][j+2][k-1][k-1],f[pre][j][0][0]+(s[0][i+1]|s[1][i+1])); 
					} 
					else if(!x)
					{
						R(f[now][j][0][y-1],f[pre][j][0][y]+s[1][i+1]);
						R(f[now][j+1][k-1][y-1],f[pre][j][0][y]+(s[0][i+1]|s[1][i+1]));
						R(f[now][j+2][k-1][k-1],f[pre][j][0][y]+(s[0][i+1]|s[1][i+1]));
					}
					else if(!y)
					{
					  	R(f[now][j][x-1][0],f[pre][j][x][0]+s[0][i+1]);
					  	R(f[now][j+1][x-1][k-1],f[pre][j][x][0]+(s[0][i+1]|s[1][i+1]));
					  	R(f[now][j+2][k-1][k-1],f[pre][j][x][0]+(s[0][i+1]|s[1][i+1]));
					}	
					else 
						R(f[now][j][x-1][y-1],f[pre][j][x][y]+(s[1][i+1]|s[0][i+1]));
				//	printf("%d %d %d %d %d\n",i,j,x,y,f[pre][j][x][y]);
					f[pre][j][x][y]=-INF;
				}
		}	
	}	
	short ans=0;
	for(int x=0;x<k;x++)
		for(int y=0;y<k;y++)
			R(ans,f[n&1][p][x][y]);
	printf("%d\n",(int)ans);
	return 0;
}