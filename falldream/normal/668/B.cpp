#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MN 1000000
#define INF 200000000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int rev=0,move=0,n,m,change=0;
int ans[1000005];

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1) move=(move+read()+n)%n;
		else 
		{
			if(!rev) rev=(move&1)?1:2;
			else
			if(move&1)
			{
				 if(rev==2) change+=1;
				 rev=0;
			}
			else
			{
				if(rev==1) change-=1;
				rev=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int pos=i+move+change*((i&1)?2:-2);while(pos<n) pos+=n;
		if(rev){if((pos&1)^(move&1)==(rev&1))pos--;else pos++;}
		pos=(pos+n-1)%n+1;
		ans[pos]=i;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}