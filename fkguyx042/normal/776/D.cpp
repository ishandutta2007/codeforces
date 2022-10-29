#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 200005
#define M 200005
#define seed 23333

using namespace std;
int i,j,m,n,p,k,a[N],A[N][3],fa[N],x,y;
int get(int x)
{
		return fa[x]==x?x:fa[x]=get(fa[x]);
}
void link(int x,int y)
{
		fa[get(x)]=get(y);
}
int main()
{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		for (i=1;i<=m;++i) 
		{
				scanf("%d",&x);
				fa[i]=i; fa[i+m]=i+m;
				for (;x--;)
				{
						scanf("%d",&y);
						A[y][++A[y][0]]=i;
				}
		}
		for (i=1;i<=n;++i) if (!a[i])
		{
				link(A[i][1],A[i][2]+m);
				link(A[i][2],A[i][1]+m);
		}
		else 
		{
				link(A[i][1],A[i][2]);
				link(A[i][1]+m,A[i][2]+m);
		}
		for (i=1;i<=m;++i) if (get(i)==get(i+m)) 
		{
				puts("NO");
				return 0;
		}
		puts("YES");
}