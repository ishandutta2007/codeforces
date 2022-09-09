#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXL = 2e5 + 5;
using namespace std;

int n,m;
char a[MAXL],b[MAXL];
int f[MAXL],g[MAXL];

inline bool check(int mid)
{
	for(int i=1; i+mid-1<=n; ++i)
	{
		int j=i+mid-1;
		if(f[i-1] + g[j+1] >= m) return 1;
	}
	return 0;
}

int main(void)
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1), m=strlen(b+1);
	
	for(int i=1; i<=n; ++i)
	{
		if(b[f[i-1]+1] == a[i]) f[i]=f[i-1]+1;
		else f[i] = f[i-1];
		if(f[i]==m)
		{
			for(++i; i<=n; ++i) f[i]=m;
			break;
		}
	}
	
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);
	for(int i=1; i<=n; ++i)
	{
		if(b[g[i-1]+1] == a[i]) g[i]=g[i-1]+1;
		else g[i] = g[i-1];
		if(g[i]==m)
		{
			for(++i; i<=n; ++i) g[i]=m;
			break;
		}
	}
	reverse(g+1,g+n+1);
	
	int l=0, r=n;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}