#include<iostream>
#include<cstdio>
#define MAXN 1000000 
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,k;
bool mark[2005];
int s[1005],q[MAXN+5],top=1,cnt=0,d[MAXN+5];

int main()
{
	k=read();n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read()-k+1000;
		if(!mark[x]) mark[x]=1,s[++cnt]=x-1000;
	}
	d[0]=1;
	for(int i=1;i<=top;i++)
		for(int j=1;j<=cnt;j++)
		{
			if(s[j]+q[i]==0) return 0*printf("%d",d[q[i]]);
			if(s[j]+q[i]<=MAXN&&s[j]+q[i]>=0&&!d[s[j]+q[i]]) d[s[j]+q[i]]=d[q[i]]+1,q[++top]=s[j]+q[i];
		}
	puts("-1");
	return 0;
}