#include <cstdio>
#include <vector>
#include <cassert>
#define NDEBUG

using ll = long long;
const int MN = 1e5 + 100;
const int MV = 2e6 + 100;
const int MOD = 998244353;
const ll INF = 2.5e17;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

struct intm
{
public:
	int v;
	operator int() const {return v;}
	intm(int v = 0) : v(v) {}
	intm operator + (intm o) const {return v+o.v<MOD?v+o.v:v+o.v-MOD;}
	intm operator - (intm o) const {return v<o.v?v-o.v+MOD:v-o.v;}
	intm operator * (intm o) const {return ti(tl(v)*o.v%MOD);}
};
int gcd(int a, int b)
{
	return a ? gcd(b%a, a) : b;
}
intm inv[MV];
struct frac
{
public:
	int n, d;
	frac(int n = 0, int d = 1) : n(n), d(d)
	{
		int g = gcd(n, d);
		frac::n /= g;
		frac::d /= g;
	}
	bool operator < (frac o) const {return tl(n)*o.d < tl(d)*o.n;}
	intm get_value()
	{
		return intm(n)*inv[d];
	}
};


ll pow(ll b, int p)
{
	ll r = 1LL;
	for(;p;p>>=1, b=b*b%MOD) if(p&1) r=r*b%MOD;
	return r;
}

void pcpmod()
{
	inv[1] = intm(1);
	for(int i = 2;i < MV;++i)
		inv[i] = inv[MOD%i]*intm(MOD-MOD/i);
}

int N;
int x[MN], v[MN], p[MN];

struct St//chance of answer being >= value
{
public:
	frac t;
	intm p;
};

std::vector<St> a[1<<18][4];//0 = flies to right (p), 1 = flies to left (1-p), 0th bit = left, 1st bit = right
void join(std::vector<St> * a, std::vector<St> * b, std::vector<St> * c)
{
	int A = a->size(), B = b->size(), i = 0, j = 0;
	c->clear();
	for(;i < A && j < B;)
		if(a->at(i).t < b->at(j).t)
			c->push_back({a->at(i).t, a->at(i).p*b->at(j).p}), ++i;
		else if(b->at(j).t < a->at(i).t)
			c->push_back({b->at(j).t, a->at(i).p*b->at(j).p}), ++j;
		else
			c->push_back({a->at(i).t, a->at(i).p*b->at(j).p}), ++i, ++j;
}
void comb(std::vector<St> * a, std::vector<St> * b, std::vector<St> * c, intm pa)
{
	int A = a->size(), B = b->size(), i = 0, j = 0;
	intm pb = intm(1) - pa;
	c->clear();
	for(;i < A && j < B;)
		if(a->at(i).t < b->at(j).t)
			c->push_back({a->at(i).t, a->at(i).p*pa+b->at(j).p*pb}), ++i;
		else if(b->at(j).t < a->at(i).t)
			c->push_back({b->at(j).t, a->at(i).p*pa+b->at(j).p*pb}), ++j;
		else
			c->push_back({a->at(i).t, a->at(i).p*pa+b->at(j).p*pb}), ++i, ++j;
}
std::vector<St> temp[2];
void dq(int n, int l, int r)
{
	if(r-l>1)
	{
		int m = l + (r-l)/2;
		dq(n<<1, l, m);
		dq(n<<1|1, m, r);
		for(int i = 0;i < 2;++i)
			for(int j = 0;j < 2;++j)
			{
				join(a[n<<1]+i, a[n<<1|1]+j*2, temp);
				join(a[n<<1]+(2|i), a[n<<1|1]+(j<<1|1), temp+1);
				comb(temp, temp+1, a[n]+(i+j*2), inv[100]*intm(p[m]));
				/*
				for(St x : temp[0]) printf("t: %d/%d, p: %d\n", x.t.n, x.t.d, ti(x.p));
				printf("+\n");
				for(St x : temp[1]) printf("t: %d/%d, p: %d\n", x.t.n, x.t.d, ti(x.p));
				printf("=\n");
				for(St x : a[n][i+j*2]) printf("t: %d/%d, p: %d\n", x.t.n, x.t.d, ti(x.p));
				printf("!\n");
				//*/
			}
	}
	else
	{
		if(v[l]>v[r]) a[n][0].push_back({frac(x[r]-x[l], v[l]-v[r]), intm(1)});
		a[n][2].push_back({frac(x[r]-x[l], v[l]+v[r]), intm(1)});
		if(v[l]<v[r]) a[n][3].push_back({frac(x[r]-x[l], v[r]-v[l]), intm(1)});
		for(int i = 0;i < 4;++i)
			a[n][i].push_back({frac(1, 0), intm(a[n][i].empty())});//top everything off
	}
}

intm get(std::vector<St> * a)
{
	intm r;
	for(int i = 0;i+1 < a->size();++i)
		r = r + a->at(i).t.get_value()*(a->at(i).p - a->at(i+1).p);
	return r;
}

intm f;
int main(void)
{
	pcpmod();
	scanf("%d", &N);
	if(N==1) return printf("0\n"), 0;
	for(int i = 0;i < N;++i)
		scanf("%d%d%d", x+i, v+i, p+i);
	dq(1, 0, N-1);
	//for(St x : a[2][2]) printf("t: %d/%d, p: %d\n", x.t.n, x.t.d, ti(x.p));

	f = f + intm(p[0]*p[N-1])*              inv[10000]*get(a[1]);
	f = f + intm((100-p[0])*p[N-1])*        inv[10000]*get(a[1]+1);
	f = f + intm(p[0]*(100-p[N-1]))*        inv[10000]*get(a[1]+2);
	f = f + intm((100-p[0])*(100-p[N-1]))*  inv[10000]*get(a[1]+3);

	printf("%d\n", ti(f));
	return 0;
}