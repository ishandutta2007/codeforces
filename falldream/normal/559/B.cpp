#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MN 500000
#define ull unsigned long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;ull pw[MN+5],ha[MN+5],Pw[50];
char st[MN+5],St[MN+5];

ull Solve(int l,int r,int dep)
{
	if((r-l+1)&1) return ha[r]-ha[l-1]*pw[r-l+1];
	int mid=l+r>>1;
	ull Ha1=Solve(l,mid,dep+1);ull Ha2=Solve(mid+1,r,dep+1);
	if(Ha1>Ha2) swap(Ha1,Ha2);
	return Ha1*Pw[dep]+Ha2; 
}

int main()
{
	srand(2333U);
	pw[0]=1; for(int i=1;i<=MN;++i) pw[i]=pw[i-1]*23333;
	for(int i=1;i<=40;++i) 
		for(int j=0;j<30;++j)
			if(rand()&1) Pw[i]|=1LL<<j; 
	scanf("%s",st+1);scanf("%s",St+1);n=strlen(st+1);
	for(int i=1;i<=n;++i) ha[i]=ha[i-1]*23333+st[i];
	ull ha1=Solve(1,n,1);
	for(int i=1;i<=n;++i) ha[i]=ha[i-1]*23333+St[i];
	ull ha2=Solve(1,n,1);
	puts(ha1==ha2?"YES":"NO");
	return 0;
}