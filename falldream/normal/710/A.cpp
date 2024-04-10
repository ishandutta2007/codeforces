#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#include<string.h>
#include<cstdlib>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n;
char l;
int main()
{
	l=getchar();
	n=read();
	if(n==8||n==1)
	{
	    if(l=='a'||l=='h')
	    {
	    	cout<<"3";
	    }
	    else
	       {
	       	   cout<<"5";
	       }
	}
	else
	{
		if(l=='a'||l=='h')
	    {
	    	cout<<"5";
	    }
	    else
	        cout<<"8";
	}
	return 0;
}