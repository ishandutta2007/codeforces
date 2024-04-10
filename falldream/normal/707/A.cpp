#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')	{ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,m;
char chr;
bool yes;
int main()
{
	yes= false;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	    {
	        do {chr = getchar();}
             while(chr!='C'&&chr!='M'&&chr!='W'&&chr!='B'&&chr!='G'&&chr!='Y');
             if(chr=='Y'||chr=='M'||chr=='C')
                 yes = true;
	    }
	if(yes==true)
	    cout<<"#Color";
	else
	    cout<<"#Black&White";
    return 0;
}