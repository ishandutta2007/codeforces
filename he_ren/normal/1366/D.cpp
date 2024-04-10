#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
const int MAXA = 1e7 + 5;

int p[MAXA], pcnt=0, q[MAXA];
bool isnp[MAXA];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i])
			p[++pcnt] = i,
			q[i] = i;
		for(int j=1; j<=pcnt && (ll)i*p[j] <= n; ++j)
		{
			isnp[i*p[j]] = 1;
			q[i*p[j]] = p[j];
			if(i%p[j] == 0) break;
		}
	}
}

int a[MAXN], ans[MAXN][2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mxa = 0;
	for(int i=1; i<=n; ++i)
		mxa = max(mxa, a[i]);
	
	sieve(mxa);
	
	for(int i=1; i<=n; ++i)
	{
		int x = a[i];
		
		vector<int> res;
		while(x>1)
		{
			int tmp = q[x];
			while(x%tmp == 0) x/=tmp;
			res.push_back(tmp);
		}
		
		if((int)res.size() < 2) ans[i][0] = ans[i][1] = -1;
		else
		{
			int x = res[0];
			int y = 1;
			for(int j=1; j<(int)res.size(); ++j)
				y *= res[j];
			
			ans[i][0] = x; ans[i][1] = y;
		}
	}
	
	for(int j=0; j<=1; ++j, putchar('\n'))
		for(int i=1; i<=n; ++i)
			printf("%d ",ans[i][j]);
	return 0;
}