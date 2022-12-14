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
	int b=0;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(b==0)
		{
			if(x==1)
			{
				cout<<"2"<<endl;
				continue;
			}
			if(x%2==0)
			   b=1;
			else
			   b=2;
		}
		else
		   {
		   	    if(x%2==0)
		   	       b=3-b;
		   }
		cout<<b<<endl;
	}
	return 0;
}