#include<bits/stdc++.h>
#define MN 22
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[1<<MN],b[1<<MN],s[(1<<MN)+5],ans,n,m;
void Solve(int x)
{
	if(a[x]) return;a[x]=1;
	if(b[x]) Solve((1<<n)-1-x);
	for(int j=0;j<n;++j) if(x&(1<<j)) Solve(x^(1<<j));	
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i) s[i]=read(),b[s[i]]=1;
	for(int i=1;i<=m;++i)
		if(!a[s[i]]) ++ans,Solve((1<<n)-1-s[i]);
	cout<<ans;
	return 0;
}