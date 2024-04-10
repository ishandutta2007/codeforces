#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

//bool isnp[MAXN];
//int p[MAXN], divi[MAXN], pcnt=0;
//void sieve(int n)
//{
//	isnp[0] = isnp[1] = 1;
//	for(int i=2; i<=n; ++i)
//	{
//		if(!isnp[i]) p[++pcnt] = divi[i] = i;
//		for(int j=1; j<=pcnt && (ll)i * p[j] <= n; ++j)
//		{
//			isnp[i*p[j]] = 1;
//			divi[i*p[j]] = p[j];
//			if(i%p[j] == 0) break;
//		}
//	}
//}

int m;
vector<int> p,q;

void get_pq(int n)
{
	p.clear(); q.clear();
	for(int i=2; (ll)i*i<=n && n>1; ++i)
		if(n%i == 0)
		{
			int cnt = 0;
			while(n%i == 0)
				n/=i, ++cnt;
			p.push_back(i); q.push_back(cnt);
		}
	if(n>1) p.push_back(n), q.push_back(1);
	
	m = (int)p.size();
}

int fob1, fob2;

void print(int dep,int cur)
{
	if(dep >= m){ if(cur!=fob1 && cur!=fob2) printf("%d ",cur); return;}
	
	for(int i=0; i<=q[dep]; ++i, cur *= p[dep])
		print(dep+1,cur);
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	get_pq(n);
	
	if(m == 1)
	{
		int now = 1;
		for(int i=1; i<=q[0]; ++i)
			now *= p[0],
			printf("%d ",now);
		printf("\n0\n"); return;
	}
	if(m == 2)
	{
		if(p[0] * p[1] == n)
		{
			printf("%d %d %d",p[0],p[1],n);
			printf("\n1\n"); return;
		}
		printf("%d ",p[0] * p[1]);
		for(int i=1, cur=p[0]; i<=q[0]; ++i, cur*=p[0])
		{
			int num = cur;
			for(int j=0; j<=q[1]; ++j, num*=p[1]) if(i!=1 || j!=1)
				printf("%d ",num);
		}
		for(int i=1, cur=p[1]; i<=q[1]; ++i, cur*=p[1])
			printf("%d ",cur);
		printf("\n0\n"); return;
	}
	
	fob1 = p[0] * p[m-1];
	for(int i=0; i<m; ++i)
	{
		fob2 = (i == m-1)? fob1: p[i] * p[i+1];
		for(int j=1, cur=p[i]; j<=q[i]; ++j, cur*=p[i])
			print(i+1, cur);
		printf("%d ",fob2);
	}
	printf("\n0\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}