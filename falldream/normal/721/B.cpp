#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define MAXN 100
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,st=0,wa=0;
char s[MAXN+5][MAXN+5],c[MAXN+5];
int main()
{
	n=read();k=read();
    for(int i=1;i<=n;i++)
    {
    	cin.getline(s[i],MAXN+5);
    }
    cin.getline(c,MAXN+5);
    int l=strlen(c);
    for(int i=1;i<=n;i++)
    {
    	int x=strlen(s[i]);
    	if(x<l)
    	   st++;
    	else
    	    if(x==l)
			{
    	        for(int j=0;j<x;j++)
    	        {
    	        	if(c[j]!=s[i][j])
    	        	{
    	        		wa++;
    	        		break;
    	        	}
    	        }
			}
    }
    cout<<1+st+(st/k)*5<<" "<<1+st+wa+((st+wa)/k)*5;
    return 0;
}