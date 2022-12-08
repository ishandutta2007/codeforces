#include <cstdio>
#define NDEBUG
#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MOD = 998244353;
struct intM
{
public:
	int v;
	intM(int v = 0) : v(v) {}
	operator int() const {return v;}
	intM operator + (intM o) const {return v+o.v<MOD?intM(v+o.v):intM(v+o.v-MOD);}
	void operator += (intM o) {v=v+o.v<MOD?v+o.v:v+o.v-MOD;}
	intM operator - (intM o) const {return v<o.v?intM(v-o.v+MOD):intM(v-o.v);}
	void operator -= (intM o) {v=v<o.v?v-o.v+MOD:v-o.v;}
	intM operator * (intM o) const {return {ti(tl(v)*o.v%MOD)};}
	void operator *= (intM o) {v=ti(tl(v)*o.v%MOD);}
};

const int MN = 1e6 + 100;
intM F[2][MN];
intM I[MN];
void pcp(void)
{
	I[1] = {1};
	for(int i = 2;i < MN;++i)
		I[i] = intM(MOD)-I[MOD%i]*intM(MOD/i);
	F[0][0] = F[1][0] = {1};
	for(int i = 1;i < MN;++i)
		F[0][i] = F[0][i-1]*intM(i), F[1][i] = F[1][i-1]*I[i];
}
intM C(int n, int k)
{
	if(n < k || k < 0) return {0};
	return F[0][n]*F[1][k]*F[1][n-k];
}

intM f;
int N;
char s[MN];

int m, n, d;//n-m>d
intM cur;
void brute(void)
{
	cur.v=0;
	intM q;
	for(int i = d;i <= n;++i)
	{
		if(i>=0) cur += q*C(n, i);
		q += C(m, i-d);
	}
}
void incd(void) {cur -= C(m+n, m+(++d));}
void decn(void)
{
	cur = (cur-C(n+m-1, d+m))*intM(MOD+1>>1); 
	--n;
}
void incm(void)
{
	cur = (cur*intM(2)-C(m+n, d+m+1));
	++m;
}

int main(void)
{
	pcp();
	scanf(" %s", s);
	for(N=1;s[N];++N) n += s[N] == '?', d -= s[N] == ')';
	brute();
	for(int i = 0;i < N-1;++i)
	{
		if(s[i] == '(') f += cur, incd();
		else if(s[i] == '?') f += cur, incm();
		if(s[i+1] == '?') decn();
		else if(s[i+1] == ')') incd();
	}
	printf("%d\n", ti(f));
	return 0;
}