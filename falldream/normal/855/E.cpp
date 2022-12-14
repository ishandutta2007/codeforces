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
long long f[11][70][11][1<<10],L,R;
int s[100],num;
long long Solve(int b,long long x)
{
//	cout<<"Solve"<<b<<" "<<x<<endl;
	num=0;for(;x;x/=b) s[++num]=x%b;
	long long res=0;s[0]=1;
	for(int i=1;i<num;++i)
		for(int k=1;k<b;++k)
			res+=f[b][i][k][0];
	for(int i=0,st=0;i<=num;++i,st^=1<<s[num-i+1])
		for(int k=(i==0);k<s[num-i];++k)
			res+=f[b][num-i][k][st];
	return res;
}

int main()
{
	for(int b=2;b<=10;++b)
	{
		f[b][0][0][0]=1;
		for(int j=1;j<=60;++j)
			for(int k=0;k<b;++k)
				for(int stat=0;stat<1<<b;++stat)
					for(int l=0;l<b;++l)
						f[b][j][k][stat]+=f[b][j-1][l][stat^(1<<k)];
	//	for(int j=1;j<=60;++j)
	//		for(int k=0;k<b;++k)
	//			for(int stat=0;stat<1<<b;++stat)
	//				f[b][j][k][stat]+=f[b][j-1][k][stat];
	//	for(int k=0;k<b;++k)
	//		for(int s=0;s<1<<b;++s)
	//			cout<<b<<" "<<2<<" "<<k<<" "<<s<<" = "<<f[b][2][k][s]<<endl;
	}
	for(int cas=read();cas;--cas)
	{
		int x=read();scanf("%lld%lld",&L,&R);
		printf("%lld\n",Solve(x,R)-Solve(x,L-1));
	}
	return 0;
}