#include <cstdio>
#include <vector>
#include <cstring>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MN = 1.5e5 + 1000;
const int MOD = 998244353;

struct intM
{
public:
	int v;
	intM(int v = 0) : v(v) {}
	void in(void) {scanf("%d", &v);}
	operator int() const {return v;}
	intM operator + (int o) const {return intM((v+o)%MOD);}
	intM operator + (intM o) const {return v+o.v<MOD?intM(v+o.v):intM(v+o.v-MOD);}
	void operator += (intM o) {v=v+o.v<MOD?v+o.v:v+o.v-MOD;}
	intM operator - (int o) const {return v-o<0?intM(v-o+MOD):intM(v-o);}
	intM operator - (intM o) const {return v-o.v<0?intM(v-o.v+MOD):intM(v-o.v);}
	intM operator * (int o) const {return intM(ti(tl(v)*o%MOD));}
	intM operator * (intM o) const {return intM(ti(tl(v)*o.v%MOD));}
	void operator *= (intM o) {v=ti(tl(v)*o.v%MOD);}
};
intM pow(intM b, int p)
{
	intM r(1);
	for(;p;p>>=1,b*=b) if(p&1) r*=b;
	return r;
}

intM invN;
int N, Q, R = 1;
std::vector<int> a[MN];
int p[MN], d[MN], s[MN];
int dfs(int n)
{
	s[n] = 1;
	for(int x : a[n])
		if(x != p[n])
			p[x] = n, d[x] = d[n]+1, s[n] += dfs(x);
	return s[n];
}
int h[MN], t[MN];
struct HUPD
{
public:
	int w;
	int L;
};
HUPD H[MN];
int C;
void dfs2(int n)
{
	for(int x : a[n])
		if(x != p[n])
		{
			if(s[x]*2 >= s[n])
			{
				h[n] = x;
				if(!~t[n]) t[n] = n;
				t[x] = t[n];
			}
			dfs2(x);
		}
	if(!~h[n] && ~t[n])
		H[t[n]] = {C, d[n]-d[t[n]]}, C += d[n]-d[t[n]];
}

intM bit[MN];
intM all;
intM work[MN], sub[MN];

void bupd(intM * b, int L, int n, intM x)
{
	for(;n <= L;n += -n&n)
		b[n-1] += x;
}
intM bqry(intM * b, int n)
{
	intM r;
	for(;n;n -= -n&n)
		r += b[n-1];
	return r;
}
void put(int v, intM d)
{
	work[v] += d;
	if(~h[v])
		bupd(bit + H[t[v]].w, H[t[v]].L, ::d[v]-::d[t[v]]+1, d*s[h[v]]);
}
void put2(int v, intM d)
{
	sub[v] += d;
	if(~t[v] && t[v] != v)
		bupd(bit + H[t[v]].w, H[t[v]].L, ::d[v]-::d[t[v]], d);
}
intM get(int n)
{
	intM r;
	for(;n;)
		if(!~t[n] || t[n] == n)
			r += sub[n]+work[p[n]]*s[n], n = p[n];
		else
			r += bqry(bit + H[t[n]].w, d[n]-d[t[n]]), n = t[n];
	return r;
}

int main(void)
{
	memset(h, -1, sizeof(h));
	memset(t, -1, sizeof(t));
	scanf("%d%d", &N, &Q);
	invN = pow(intM(N), MOD-2);
	for(int i = 1, u, v;i < N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	dfs(R);
	dfs2(R);
	//for(int i = 1;i <= N;++i) printf("NODE %d: [p:%d, d:%d, s:%d, h:%d, t:%d]\n", i, p[i], d[i], s[i], h[i], t[i]);
	int op, v;
	intM d;
	for(int i = 0;i < Q;++i)
	{
		scanf("%d%d", &op, &v);
		if(op == 1)
		{
			scanf("%d", &d.v);
			if(!d.v) continue;
			put(v, intM(MOD-d.v));
			if(v == R) all += d*N;
			else all += d*s[v], put2(v, d*(N-s[v]));
		}
		else
			printf("%d\n", invN*(all + get(v)));
	}
	return 0;
}