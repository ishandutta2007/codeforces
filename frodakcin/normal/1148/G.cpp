#include <cstdio>
#include <cassert>

int gcd(int a, int b) {return a?gcd(b%a,a):b;}

const int V = 1e7 + 10, P = 7e5;

int p[P];
bool c[V];
int n[V], d[V];

void pcp(void)
{
	for(int i = 2;i < V;++i)
	{
		if(!c[i])
			n[i] = 1, p[d[i]=++*p]=i;
		for(int j = 1, k;j <= *p && (k=i*p[j]) < V;++j)
		{
			//assert(k > 0 && !c[k]);
			c[k] = 1;
			d[k] = j;
			if(i%p[j]) n[k] = i;
			else
			{
				n[k] = n[i];
				break;
			}
		}
	}
}
void fix(int *v)
{
	int x = *v;
	*v = 1;
	for(;x > 1;x = n[x])
		*v*=p[d[x]];
}

const int MN = 1e5 + 100;
const int MD = 8;
int N, K;
int a[MN], e[MN];
int m[1<<MD], b[1<<MD];

int v[V];
int f[MD], F, w[1<<MD];
void upd(int x, int y)
{
	for(F=0;x>1;x=n[x]) f[F++] = p[d[x]];
	for(int i = 1;i < 1<<F;i++)
	{
		w[i] = w[i^1<<b[i]]*f[b[i]];
		v[w[i]] += m[i]*y;
	}
}
int count(int x)
{
	int r = 0;
	for(F=0;x>1;x=n[x]) f[F++] = p[d[x]];
	for(int i = 1;i < 1<<F;i++)
	{
		w[i] = w[i^1<<b[i]]*f[b[i]];
		r += v[w[i]];
	}
	return r;
}

int t[MN], z, C, u;
int main(void)
{
	pcp();
	m[0] = -1, b[0] = -1, w[0] = 1;
	for(int i = 1;i < 1<<MD;++i)
		m[i] = -m[i&i-1], b[i] = 31-__builtin_clz(i);
	scanf("%d%d", &N, &K);
	for(int i = 0;i < N;++i) scanf("%d", a+i), fix(a+i), upd(a[i], 1);
	t[N] = -1;
	for(int i = 0;i < N;++i)
		if((t[i]=count(a[i])) < N-1)
		{
			t[N] = i;
			t[i] = -1;
			for(int j = 0, k = 1;j < N && k <= 2;++j)
				if(i!=j&&gcd(a[i],a[j])==1)
					t[N+k++] = j, t[j] = -1;
			break;
		}
	if(!~t[N])
	{
		for(int i = 0, j = 0;i < K;++i, ++j)
		{
			for(;count(a[j])==N-i&&t[j]==N-1;++j);
			printf("%d%c", j+1, " \n"[i==K-1]), upd(a[j], -1);
		}
		return 0;
	}
	if(K == 3)
		return printf("%d %d %d\n", t[N]+1, t[N+1]+1, t[N+2]+1), 0;
	upd(a[t[N]], -1), upd(a[t[N+1]], -1), upd(a[t[N+2]], -1);
	for(int i = 0;i < N;++i)
		if(~t[i])
			z += t[i] = count(a[i]) == N-3;
	if(z >= K)
	{
		for(int i = 0, j = 0;i < K;++i, ++j)
		{
			for(;t[j]!=1;++j);
			printf("%d%c", j+1, " \n"[i+1==K]);
		}
		return 0;
	}
	for(int i = 0;i < V;++i) v[i] = 0;
	for(int i = 0, j = 0;i < N;++i)
	{
		for(;!~t[i];++j, ++i);
		e[i-j] = a[i];
	}
	for(int i = 17, j;i >= 0;--i)
		if((C|1<<i)<=N-3)
		{
			for(j = C, C|=1<<i;j < C;++j)
				upd(e[j], 1);
			u = 0;
			for(j = 0;j < C;++j)
				u += count(e[j]) != C;
			if(u+3 >= K)
				for(j = C, C^=1<<i;j > C;)
					upd(e[--j], -1);
		}
	u = z = 0;
	for(int i = 0;i < C;i++)
		u += t[i] = count(e[i]) != C;
	upd(e[C], 1);
	for(int i = 0;i < C;i++)
		if(!t[i] && count(e[i]) == C)
			t[i] = 2, ++z;
	if(u+4 == K)
		if(z)
			printf("%d %d ", t[N]+1, t[N+1]+1), u = 1;
		else
			printf("%d %d %d ", t[N]+1, t[N+1]+1, t[N+2]+1), u = 0;
	else
		printf("%d %d %d ", t[N]+1, t[N+1]+1, t[N+2]+1), u = K-4-u;
	for(int i = 0, j = 0;i < C;++i)
	{
		for(;t[N]==i+j||t[N+1]==i+j||t[N+2]==i+j;++j);
		if(t[i] == 1 || (t[i] == 2 && u-->0))
			printf("%d ", i+j+1);
	}
	for(int i = 0;i <= C;++i)
		if(t[N]==i||t[N+1]==i||t[N+2]==i)
			++C;
	printf("%d\n", C+1);
	return 0;
}