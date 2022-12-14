#include<iostream>
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
int ans=0,n;
int ansnum[MAXN+5];
char s[MAXN+5];
int main()
{
    n=read();
    cin.getline(s,MAXN+5);
    int nown=0;
    for(int i=0;s[i];i++)
    {
    	if(s[i]=='W')
    	{
    		if(nown>0)
    		   ansnum[++ans]=nown;
    		nown=0;
    	}
    	else
    	    {
    	    	nown++;
    	    }
    }
    if(nown)
       ansnum[++ans]=nown;
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
       cout<<ansnum[i]<<" ";
    return 0;
}