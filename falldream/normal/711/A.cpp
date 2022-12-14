#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1; ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
char c[1010][10];
int main()
{
	bool yes = false;
	int n=read();
	for(int i=1;i<=n;i++)
	{
		cin.getline(c[i],10);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i][0]=='O'&&c[i][1]=='O')
		{
			yes = true;
			c[i][0]=c[i][1]='+';
			break;
		}
		if(c[i][3]=='O'&&c[i][4]=='O')
		{
			yes = true;
			c[i][3]=c[i][4]='+';
			break;
		}
}
	
	if(yes)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<c[i]<<endl;
		}
	}
	else
	   cout<<"NO"<<endl;
	return 0;
}