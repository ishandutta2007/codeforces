#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int c1=0,c2=0,c3=0,c4=0;
char s[100005];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		s[i]=getchar();
    }
    for(int i=1;i<=n;i++)
    {
    	if(i&1&&s[i]=='r') c1++;
    	if(i&1&&s[i]=='b') c3++;
    	if(~i&1&&s[i]=='r') c4++;
    	if(~i&1&&s[i]=='b') c2++;
    }
    cout<<min(max(c1,c2),max(c3,c4));
    return 0;
}