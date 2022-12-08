#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e6 + 100;
const ll INF = 1e16;
int N, M, P;
int a[MN];

void out(vector<ll>& x)
{
	for(int i = 0;i < x.size();i++)
		printf("%lld%c", x[i], " \n"[i+1==x.size()]);
}
struct DAT
{
public:
	ll s;
	vector<ll> f;
	DAT() {s = 0LL; f.clear();}
	DAT(int v)
	{
		s = tl(v);
		f = {tl(P)-v};
	}
	DAT(const DAT& A, const DAT& B)
	{
		s = A.s + B.s;
		const vector<ll> &a = A.f, &b = B.f;
		vector<ll> e(0);
		for(int i = 0;i < a.size();i++) e.push_back(A.s+a[i]-tl(i+1)*P);
		int x = 0, y = 0;
		ll da = -INF, db = -A.s;
		for(int i = 0;i < a.size()+b.size();i++)
			if(y!=b.size()&&(x==a.size()||(a[x]+(da>e[x]?da-e[x]:0LL))>b[y]+db))
				f.push_back(b[y]+db), da = b[y++];
			else
				f.push_back(a[x]+(da>e[x]?da-e[x]:0LL)), db += P, x++;
	}
	ll operator() (const ll& x) const
	{
		return x+s-tl(P)*(upper_bound(f.begin(),f.end(),x) - f.begin());
	}
};

DAT v[MN*4];
void build(int n, int l, int r)
{
	if(r-l>1)
	{
		int m = l + (r-l>>1);
		build(n<<1, l, m), build(n<<1|1, m, r);
		v[n] = {v[n<<1], v[n<<1|1]};
	}
	else
		v[n] = {a[l]};
	//printf("%d %d %d: ", n, l, r); out(v[n].f);
}
ll qry(int n, int l, int r, int ql, int qr, ll x)
{
	if(ql <= l&&r <= qr)
		return v[n](x);
	int m = l + (r-l>>1);
	if(ql < m) x = qry(n<<1, l, m, ql, qr, x);
	if(m < qr) x = qry(n<<1|1, m, r, ql, qr, x);
	return x;
}

int main(void)
{
	scanf("%d%d%d", &N, &M, &P);
	for(int i = 0;i < N;i++)
		scanf("%d", a + i);
	build(1, 0, N);
	for(int i = 0, a, b;i < M;i++)
		scanf("%d%d", &a, &b), printf("%lld\n", qry(1, 0, N, --a, b, 0LL));
	return 0;
}