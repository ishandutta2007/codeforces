#include<iostream>
#include<cstdio>
#define MN 100000
#define Rep(I,a,b) for(int I=(a);I<=(b);++I)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;char st[MN+5];
long long f[MN+5][2][2][2],ans=0;
int main()
{
	n=read();m=read();scanf("%s",st+1);
	f[0][0][0][0]=1;
	Rep(i,1,n)Rep(j,0,1)Rep(k,0,1)Rep(l,0,1)Rep(x,0,m-1)
	{
		int J=max(i-1-k,i-2-j+(x==st[i-1]-'a'));
		int K=max(i-1-k+(x==st[i]-'a'),i-1-l);K=max(K,J);
		int L=max(i-1-l+(x==st[i+1]-'a'),K);
		J=max(J,0);K=max(K,0);L=max(L,0);
		if(i-1-J>1||i-K>1||i-L>1) continue;
		f[i][i-1-J][i-K][i-L]+=f[i-1][j][k][l];
	}
	Rep(j,0,1)Rep(l,0,1) ans+=f[n][j][1][l]; 
	printf("%lld\n",ans);
	return 0;
}