#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int a,b,f,g,k,now,ans;
int main()
{
	re(a),re(b),re(f),re(k);
	now=b;g=a-f;
	if((k==1&&(b<f||b<g)) || (k==2 &&(b<f||b<g+g)))
	{
		puts("-1");
		return 0;
	}	
	if((b<g+g || b<f+f)&&k>2)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<k;++i)
	{
		if(i&1)
		{
			if(now>=a+g)
				now-=a;
			else 
				now=b-g,++ans;
		}
		else
		{
			if(now>=a+f)
				now-=a;
			else 
				now=b-f,++ans;
		}
	}
	if(now<a)++ans;
	printf("%d\n",ans);
}