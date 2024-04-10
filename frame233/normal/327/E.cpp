#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#define lowbit(x) ((x)&(-x))
const int mod=1000000007;
int f[1<<24],a[1<<24],b[2];
inline void add(int &x,const int &y){(x+=y)>=mod&&(x-=mod);}
int main()
{
    int n,m;
    scanf("%d",&n);
    int maxx=(1<<n)-1;
    for(register int i=1;i<=n;++i) scanf("%d",&a[1<<(i-1)]);
    scanf("%d",&m);
    b[0]=b[1]=-1;
    for(register int i=0;i<m;++i) scanf("%d",&b[i]);
    f[0]=1;
	for(register int i=1;i<=maxx;++i)
	{
		register int tmp=lowbit(i);
		a[i]=a[i^tmp]+a[tmp];
		if(a[i]!=b[0]&&a[i]!=b[1])
		{
			for(register int j=i;j;j^=lowbit(j))
			{
				add(f[i],f[i^lowbit(j)]);
			}
		}
	}
	printf("%d\n",f[maxx]);
    return 0;
}