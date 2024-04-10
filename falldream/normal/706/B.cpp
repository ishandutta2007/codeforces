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
#include<cmath>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,s[100010],x,q;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
	    s[i]=read();
	}	
    sort(s+1,s+n+1);
    q=read();
    for(int i=1;i<=q;i++)
    {
    	x=read();
    	cout<<upper_bound(s+1,s+n+1,x)-s-1<<endl;
    }
	return 0;	
}