#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6;
const int MAXN = maxn + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int p[MAXN], pcnt=0;
bool isnp[MAXN];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) p[++pcnt] = i;
		for(int j=1; j<=pcnt && (ll)i * p[j] <= n; ++j)
		{
			isnp[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

int ans[MAXN];

int main(void)
{
	sieve(maxn);
	
	queue<int> q;
	for(int i=2; i<=maxn; ++i)
	{
		if(!isnp[i]) q.push(i);
		if(q.front() * q.front() == i) q.pop();
		
		ans[i] = (int)q.size();
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]+1);
	}
	return 0;
}