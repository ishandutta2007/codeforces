#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int a[N],pre[N],last[N],tree[N];
bool ok[N];
void push(int x,int val)
{
	while(x<N)tree[x]=min(tree[x],val),x+=x&-x;
}
int ask(int x)
{
	int res=1<<30;
	do
	{
		res=min(res,tree[x]);
		x-=x&-x;
	}while(x);
	return res;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		pre[i]=last[a[i]];
		last[a[i]]=i;
		tree[i]=1<<30;
		if(a[i]!=1)ok[1]=1;
	}
	for(int i=1;i<=n+1;++i)
	{
		if(ask(i-1)>last[i])ok[i]=1;
		push(i,last[i]);
	}
	for(int i=n;i>=1;--i)
	{
		if(ask(a[i]-1)>pre[i])ok[a[i]]=1;
		push(a[i],pre[i]);
	}
	int ans=1;
	while(ok[ans])++ans;
	write(ans);
}