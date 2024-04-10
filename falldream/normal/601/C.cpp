#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double f[105][100005];
int n,m,tot=0;
inline double F(int b,int c){return c?f[b][c]-f[b][c-1]:f[b][c];}
int main()
{
	n=read();m=read();f[0][0]=1;
	if(m==1) return 0*puts("1");
	for(int i=1;i<=n*m;++i) f[0][i]=1;
	for(int i=1;i<=n;++i)
	{
		int x=read();tot+=x;
		for(int j=1;j<=i*m;++j)
		{
			f[i][j]+=f[i-1][j-1]-(j>m?f[i-1][j-m-1]:0);
			if(j>=x) f[i][j]-=F(i-1,j-x);
			//cout<<i<<" "<<j<<" "<<f[0][i][j]<<" "<<f[1][i][j]<<endl; 
		}
		for(int j=1;j<=n*m;++j)	f[i][j]+=f[i][j-1];
	}
	double Tot=0,Ok=0;
	for(int j=0;j<=n*m;++j) Tot+=F(n,j),Ok+=(j<tot?F(n,j):0);
	printf("%.10lf",Ok/Tot*(m-1)+1); 
	return 0;
}