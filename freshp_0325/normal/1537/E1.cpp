#include<bits/stdc++.h>
using namespace std;
char s[1005];
int n,k;
bool getMin(int x,int y)
{
	for(int i=1;i<=3*n;++i)
	{
		int lx=i%x,ly=i%y;
		if(lx==0)	lx=x;
		if(ly==0)	ly=y;
		if(s[lx]<s[ly])	return true;
		if(s[lx]>s[ly])	return false;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	int ls=1;
	for(int i=2;i<=n;++i)	if(getMin(i,ls))	ls=i;
	for(int i=1;i<=k;++i)
	{
		int x=i%ls;
		if(x==0)	x=ls;
		putchar(s[x]);
	}
	return 0;
}