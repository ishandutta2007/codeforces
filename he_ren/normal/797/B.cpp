#include<cstdio>
const int MAXN = 1e5 + 5;
const int inf = 1e6 + 5;

inline int max(int a,int b){ return a>b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN],f[3]={-inf,-inf};

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		int p=f[0], q=f[1];
		if(a[i]&1)
		{
			if(q!=-inf) chk_max(f[0], q+a[i]);
			chk_max(f[1], max(p+a[i], a[i]));
		}
		else
		{
			chk_max(f[0], max(f[0]+a[i], a[i]));
			if(f[1]!=-inf) chk_max(f[1], f[1]+a[i]);
		}
	}
	
	printf("%d",f[1]);
	return 0;
}