#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;

bool isnp[MAXN];
int p[MAXN],pcnt=0,q[MAXN];
inline void sieve(int n)
{
	isnp[0]=isnp[1]=1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) p[++pcnt]=i, q[i]=i;
		for(int j=1; j<=pcnt; ++j)
		{
			if((ll)i*p[j]>n) break;
			isnp[i*p[j]]=1;
			q[i*p[j]]=p[j];
			if(!(i%p[j])) break;
		}
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	
	sieve(n);
	for(int i=2; i<=n; ++i)
		q[i] = i/q[i];
	sort(q+1,q+n+1);
	for(int i=2; i<=n; ++i) printf("%d ",q[i]);
	return 0;
}