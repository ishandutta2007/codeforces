#include<cstdio>
#include<cmath>
const int MAXN = 1e2 + 5;

inline int Abs(int x){ return x<0? -x: x;}

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	int x=0, y=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='U') ++y;
		if(s[i]=='D') --y;
		if(s[i]=='L') --x;
		if(s[i]=='R') ++x;
	}
	printf("%d",n-Abs(x)-Abs(y));
	return 0;
}