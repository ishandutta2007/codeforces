#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	int n=read(),m=read(),tot=n+m;
	if(m>n) return 0*puts("-1");
	int du=int((double)tot/m/2);
	printf("%.10lf\n",(double)tot/du/2);
	return 0;
}