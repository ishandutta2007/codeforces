#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 500
#define eps 1e-11
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Matrix
{
	#define MM 101
	double s[MN+5][MN+5];
	Matrix(){memset(s,0,sizeof(s));}
	Matrix operator * (const Matrix&b)
	{
		Matrix c;
		for(int i=1;i<=MM;++i)
			for(int j=1;j<=MM;++j)
				for(int k=1;k<=MM;++k)
					c.s[i][j]+=s[i][k]*b.s[k][j];		
		return c;
	}
	#undef MM
}A,B;
int n,m,k,Kind[MN+5],b[MN+5][MN+5],du[MN+5],top=0,tot=0,pos[MN+5],id[MN+5];
double a[MN+5][MN+5],res[MN+5];
struct op{int kind,l,r;double s;}q[MN*MN+5];

void Gauss()
{
	a[1][n+1]+=1; 
//	for(int j=1;j<=n;++j) a[j][n+1]+=(double)b[1][j]/du[1];
/*	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n+1;++j)
			printf("%.5lf ",a[i][j]);
	puts("");*/ 
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
			if(fabs(a[j][i])>eps)
			{
				if(j!=i)
				{
					for(int k=i;k<=n+1;++k) swap(a[i][k],a[j][k]);
					q[++top]=(op){1,i,j,0};
				}	
				break;
			}
		if(fabs(a[i][i])<eps) continue;
		for(int j=i+1;j<=n;++j) 
		{
			double s=a[j][i]/a[i][i];
			q[++top]=(op){2,i,j,s};
			for(int k=i;k<=n+1;++k)
				a[j][k]-=a[i][k]*s;
		}
	/*	for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=n+1;++j)
				printf("%.5lf ",a[i][j]);
		puts("");*/ 
	}
	res[n]=a[n][n+1];
	for(int i=n-1;i;--i)
	{
		double t=a[i][n+1];
		for(int j=i+1;j<=n;++j) t-=a[i][j]*res[j];
		res[i]=t/a[i][i];	
	}
}

void Solve(int x)
{
	for(int i=1;i<=n;++i) id[i]=i;
	for(int j=1;j<=n;++j) res[j]=(double)b[x][j]/du[x];
	for(int i=1;i<=top;++i)
		if(q[i].kind==1) swap(id[q[i].l],id[q[i].r]);
		else res[id[q[i].r]]-=q[i].s*res[id[q[i].l]];
	for(int i=n-1;i;--i)
	{
		double t=res[i];
		for(int j=i+1;j<=n;++j) t-=a[i][j]*res[j];
		res[i]=t/a[i][i];	
	}
}

int main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;++i) if(Kind[i]=read()) pos[i]=++tot;
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();++du[x];++du[y];
		++b[x][y];++b[y][x];	
	}
	for(int i=1;i<=n;++i) ++a[i][i];
	for(int i=1;i<=n;++i) if(!Kind[i])
		for(int j=1;j<=n;++j) 
			a[j][i]-=(double)b[i][j]/du[i];
	Gauss();
	for(int i=1;i<=n;++i) if(Kind[i]) B.s[pos[i]][1]=res[i]; 
	for(int i=1;i<=n;++i) if(Kind[i])
	{
		Solve(i);
		for(int j=1;j<=n;++j) if(Kind[j]) A.s[pos[j]][pos[i]]=res[j];//cout<<i<<" -> "<<j<<" = "<<res[j]<<endl;
	}
	for(k-=2;k;k>>=1,A=A*A) if(k&1) B=A*B;
	printf("%.10lf\n",B.s[pos[n]][1]);
	return 0;
}