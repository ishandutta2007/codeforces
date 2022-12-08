#include <cstdio>
#include <algorithm>
//#define NDEBUG
#include <cassert>

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e5 + 100;
const int CH = 26;
const int NL = 18;

ll F;
int s[MN], N;
int c[MN][CH], n[2][MN][CH], m[2][MN][CH];
int a[CH];

int get(int a, int b)
{
	++b;
	int r = 0;
	for(int i = 0;i < CH;++i)
		if(c[b][i]>c[a][i])
			r|=1<<i;
	return r;
}

struct SEG
{
public:
	SEG(int n = -1, ll c = -1LL) : n(n), c(c) {}
	int n;
	ll c;
};
SEG l[MN][NL], r[MN][NL];
int L[MN], R[MN];

int main(void)
{
	for(char t;scanf(" %c", &t) != EOF;)
		if(t != '\n')
			s[N++] = t-'a';
	for(int i = 0;i < CH;++i)
		n[1][0][i] = -1, n[0][N-1][i] = N;
	for(int i = 0;i < N;++i)
	{
		for(int j = 0;j < CH;++j)
			c[i+1][j] = c[i][j], n[1][i+1][j] = n[1][i][j];
		++c[i+1][s[i]];
		n[1][i+1][s[i]] = i;
	}
	for(int i = N-1;i > 0;--i)
	{
		for(int j = 0;j < CH;++j)
			n[0][i-1][j] = n[0][i][j];
		n[0][i-1][s[i]] = i;
	}
	for(int i = 0, * q;i < N;++i)
	{
		a[0] = s[i];
		for(int j = 0;j < CH-1;++j)
			a[j+1] = j+(j>=s[i]);

		q = n[0][i];
		std::sort(a+1,a+CH, [&](int x, int y){return q[x]<q[y]||!(q[y]<q[x])&&x<y;});
		for(int j = 0, T = N;j < CH;++j)
		{
			if(!j || q[a[j]] < N) T = std::min(T, std::max(0, n[1][i][a[j]]));
			m[1][i][j] = T;
		}

		q = n[1][i];
		std::sort(a+1,a+CH, [&](int x, int y){return q[x]>q[y]||!(q[y]>q[x])&&x<y;});
		for(int j = 0, T = 0;j < CH;++j)
		{
			if(!j || q[a[j]] >= 0) T = std::max(T, std::min(N-1, n[0][i][a[j]]));
			m[0][i][j] = T;
		}
	}

	for(int i = 0;i < NL;++i)
		l[0][i] = {0, 0LL}, r[N-1][i] = {N-1, 0LL};
	for(int i = 0;i < N;++i)
		L[i] = R[i] = i;

	for(int i = 0, m, ml, mr;i < CH;++i)
	{
		for(int j = 1;j < N;++j)
		{
			l[j][0] = {::m[1][j][i], tl(j)};
			for(int k = 0;k+1 < NL;++k)
				l[j][k+1] = {l[l[j][k].n][k].n, l[j][k].c+l[l[j][k].n][k].c};
		}
		for(int j = N-2;j >= 0;--j)
		{
			r[j][0] = {::m[0][j][i], tl(N-j-1)};
			for(int k = 0;k+1 < NL;++k)
				r[j][k+1] = {r[r[j][k].n][k].n, r[j][k].c+r[r[j][k].n][k].c};
		}
		for(int j = 0;j < N;++j)
			if(L[j]>0||R[j]<N-1)
			{
				int C = get(L[j], R[j]);
				if(__builtin_popcount(C) > i+1) continue;
				ml = mr = 0;
				for(int k = NL-1, t = L[j], u;k >= 0;--k)
					if((get(u=l[t][k].n,L[j])|C)==C)
						t = u, ml|=1<<k;
				for(int k = NL-1, t = R[j], u;k >= 0;--k)
					if((get(R[j],u=r[t][k].n)|C)==C)
						t = u, mr|=1<<k;
				m = std::min(ml, mr);
				if(m+1<1<<NL)++m;
				for(int k = 0;1<<k <= m;++k)
					if(m&1<<k)
						F+=r[R[j]][k].c+l[L[j]][k].c, R[j]=r[R[j]][k].n, L[j]=l[L[j]][k].n;
			}
	}

	printf("%lld\n", F);
	return 0;
}