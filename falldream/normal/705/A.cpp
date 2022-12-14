#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int main()
{
	n=read();
	bool b=true;
	while(n)
	{
		if(b)
		   cout<<"I hate ";
		else
		   cout<<"I love ";
		if(n==1)
		   cout<<"it";
		else
		   cout<<"that ";
		n--;
		b=!b;
	}
	return 0;
}