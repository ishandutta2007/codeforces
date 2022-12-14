#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<map>
#define ll long long
#define INF 2000000000
#define MAXL 19
#define MAXN 1800000
using namespace std;

ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct tree{
	int l,r,x;
}t[MAXN+5];
ll n,x,cnt=1;
char op,ch[30];


void ins(ll x)
{
	int k=1,xx=x;	
    for(int i=1;i<=MAXL;i++)
    {
        if((x%10)%2==1)
        {
        	if(t[k].r<0)
        	{
        		t[k].r=++cnt;
        	}
        	k=t[k].r;
        }
        else
           {
           	   	if(t[k].l<0)
	        	{
	        		t[k].l=++cnt;
	        	}
	        	k=t[k].l;
           }
    	t[k].x++;
    	x/=10;
    }
}

void dec(ll x)
{
	int k=1;
    for(int i=1;i<=MAXL;i++)
    {
        if((x%10)%2==1)
        {
        	k=t[k].r;
        }
        else
           {
	        	k=t[k].l;
           }
    	x/=10;
    	t[k].x--;
    }
}

void check()
{
	int k=1;
	for(int i=strlen(ch)-1;i>=0;i--)
	{
		if(ch[i]==' ') continue;
		if(ch[i]=='1')
		{
			if(t[k].r<0)
        	{
        		puts("0");
        		return;
        	}
        	k=t[k].r;
		}
		else
		   {
		        if(t[k].l<0)
	        	{
	        		puts("0");
	        		return;
	        	}
	        	k=t[k].l;
		   }
	}
	for(int i=strlen(ch)+1;i<=MAXL;i++)
	{
		if(t[k].l<0)
	     {
	     	puts("0");
	     	return;
	     }
	     k=t[k].l;
	}
	cout<<t[k].x<<endl;
}

int main()
{ 
    n=read();
    for(int i=1;i<=MAXN;i++)
       t[i].l=t[i].r=-1,t[i].x=0;
    for(int i=1;i<=n;i++)
    {
    	op=getchar();
    	if(op=='?')
    	{ 
    		gets(ch);
    		check();
	    }
	    else
	    {
	        x=read();
	        if(op=='+')
	           ins(x);
	        else
	           dec(x);
		}
	} 
	return 0;
}