#include <cstdio>

using ll = long long;
ll k, x=1;

int c[10];
char f[] = "codeforces";
int main(void)
{
	scanf("%lld", &k);
	for(int i=0;i<10;++i) c[i]=1;
	for(int i;x<k;++i)
		for(int j=0;x<k&&j<10;++j)
		{
			x*=(c[j]+1);
			x/=c[j]++;
		}
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<c[i];++j)
			printf("%c", f[i]);
	}
	printf("\n");
	return 0;
}