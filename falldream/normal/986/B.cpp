#include<bits/stdc++.h>
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],step,pos[MN+5]; 
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;
	for(int i=1;i<=n;++i) if(a[i]!=i)
	{
		int j=pos[i];++step;
		pos[i]=i;pos[a[i]]=j;
		a[j]=a[i];a[i]=i;
	}
	puts((step^n)&1?"Um_nik":"Petr");
	return 0;
}