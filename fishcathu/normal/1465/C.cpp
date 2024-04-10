#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+1;
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
int fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),m=read(),ans=0;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=m;++i)
		{
			int l=read(),r=read();
			if(l==r)continue;
			++ans;
			if(find(l)==r)++ans;
			else fa[r]=l;
		}
		printf("%d\n",ans);
	}
}