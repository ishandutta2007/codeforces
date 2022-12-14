#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAXN 50000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'|ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int num[50],nown=0,nows=0,l;
char ch[MAXN+10];
bool yes=false;
void print(int i,int j)
{
	for(int m=0;m<i;m++)
	{
		if(ch[m]=='?')
		   cout<<"A";
		else
		   cout<<ch[m];
	}
	for(i;i<=j;i++)
	{
		if(ch[i]!='?')
		{
			cout<<ch[i];
		}
		else
		    {
		    	for(int k=0;k<=25;k++)
		    	{
		    		if(!num[k])
		    	     {
		    	     	cout<<(char)(k+'A');
		    	     	num[k]=1;  	     	
		    	     	break;
		    	     }
		    	}
		    }
	}
	for(int m=j+1;m<l;m++)
	{
		if(ch[m]=='?')
		   cout<<"A";
		else
		   cout<<ch[m];
	}
}

int main()
{
    cin.getline(ch,MAXN+5);
    l=strlen(ch);
    if(l<26)
    {
    	puts("-1");
    	return 0;
    }
    for(int i=0;i<=25;i++)
    {
    	if(ch[i]=='?')
    	nows++;
    	else
    	{
    	   num[ch[i]-'A']++;
    	   if(num[ch[i]-'A']==1)
    	      nown++;
		}
    }
    for(int i=0,j=25;j<l;)
    {
    	if(nown+nows==26)
        {
        	print(i,j);
        	return 0;
        }
        if(ch[i]=='?')
           nows--;
        else
        {
           num[ch[i]-'A']--;
           if(num[ch[i]-'A']==0)
              nown--;
        }
        i++;j++;
        if(j<l)
        {
        	if(ch[j]=='?')
        	   nows++;
        	else
        	   {
        	   	   num[ch[j]-'A']++;
        	   	   if(num[ch[j]-'A']==1)
        	   	       nown++;
        	   }
        }
	}
	puts("-1");
	return 0;
}