#include<cstdio>
#include<queue> 
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
bool dp[2005][2005];
char in[2005][10],p[10][10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
void Output(int now,int rest)
{
	for(int i=9;~i;--i)
	{
		int calc=0,cnt=0;
		for(int j=0;j<=6;++j)
		{
			if(p[i][j]=='1')	++cnt;
			if(p[i][j]=='1' && in[now][j]=='0')	++calc;
			if(p[i][j]=='0' && in[now][j]=='1')	goto reset2;
		}
		if(dp[now-1][rest-calc])
		{
			putchar(i+'0');
			Output(now-1,rest-calc);
			return ;
		}
		reset2:;
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=n;i;--i)	scanf("%s",in[i]);
	dp[0][0]=true;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=9;++j)
		{
			int calc=0,cnt=0;
			for(int l=0;l<=6;++l)
			{
				if(p[j][l]=='1')	++cnt;
				if(p[j][l]=='1' && in[i][l]=='0')	++calc;
				if(p[j][l]=='0' && in[i][l]=='1')	goto reset;
			}
			for(int l=0;l<=k-calc;++l)	dp[i][l+calc]|=dp[i-1][l];
			reset:;
		}
	}
	if(!dp[n][k])	return puts("-1")&0;
	Output(n,k);
	return 0;
}