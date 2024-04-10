#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5E5+10;
ll read()
{
    ll a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
} 
int fa[N];
bitset<N>b;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		int l,r;
		if(read()==1)l=read(),r=0;
		else l=read(),r=read();
		l=find(l);
		r=find(r);
		if(l!=r)
		{
			fa[l]=r;
			b[i]=1;
		}
	}
	int a1=1,a2=b.count();
	const int p=1E9+7;
	for(int i=a2,j=2;i;i>>=1,j=j*1ll*j%p)if(i&1)a1=a1*1ll*j%p;
	printf("%d %d\n",a1,a2);
	for(int i=1;i<=n;++i)if(b[i])printf("%d ",i);
}