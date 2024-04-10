#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
#define MN 151
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
struct Road{int f,t,d;}a[MN+5];
bool cmp(const Road&x,const Road&y){return x.d<y.d;}
struct Matrix
{
	bitset<MN+5> r[MN+5],c[MN+5];
	Matrix operator * (const Matrix&b)
	{
		Matrix s;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				s.r[i][j]=s.c[j][i]=(r[i]&b.c[j]).any();
		return s;
	}
	void Set(int x,int y){r[x-1][y-1]=c[y-1][x-1]=1;}
	bool ok(){return r[n][0]|r[n-1][0];}
}A,B,C[40],NA;

void Solve(int beg,int t)
{
	//cout<<"Solve"<<beg<<" "<<t<<endl;
	if(!t) return;C[0]=B;int i,flag=0,used=0;
	for(i=1;(1<<i)<=t;++i)	C[i]=C[i-1]*C[i-1];
	for(;~i;--i) if(used+(1<<i)<=t)
	{
		NA=C[i]*A;	
		if(!NA.ok()) used+=(1<<i),A=NA;
		else flag=1;
	}	
	if(flag) {printf("%d",beg+used+1);exit(0);}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) a[i].f=read(),a[i].t=read(),a[i].d=read();a[++m]=(Road){n+1,n+1,int(1e9)+1000};
	sort(a+1,a+m+1,cmp);B.Set(n+1,n);B.Set(n+1,n+1);A.Set(1,1);
	Solve(0,a[1].d);
	for(int i=1;i<m;++i)
		B.Set(a[i].t,a[i].f),Solve(a[i].d,a[i+1].d-a[i].d);
	puts("Impossible");
	return 0;
}