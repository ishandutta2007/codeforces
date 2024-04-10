#include <cstdio>
#include <vector>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 1e5+10, MV = 1<<20;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, x[MN], t[MN], p[MN], l[MN];
ll T, ans[MN];
std::vector<int> a[MN];

struct ST
{
	public:
		ll c[MV*2], t[MV*2];
		void upd(int n, int l, int r, int q, int qv)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				if(q<m) upd(n<<1,l,m,q,qv);
				else upd(n<<1|1,m,r,q,qv);
			}
			c[n]+=qv;
			t[n]+=(ll)q*qv;
		}
		ll qry(int n, int l, int r, ll mt)
		{
			if(t[n] <= mt) return c[n];
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				if(mt<t[n<<1]) return qry(n<<1, l, m, mt);
				else return c[n<<1]+qry(n<<1|1, m, r, mt-t[n<<1]);
			}
			else
				return std::min(mt/l, c[n]);
		}
} st;

void dfs(int n=1, ll d=0)
{
	//printf("%d: %lld\n", n, d);
	st.upd(1, 1, MV, t[n], x[n]);
	if(d*2<=T)
		ans[n]=st.qry(1, 1, MV, T-d*2);
	else
		ans[n]=-INF;
	ll h[2]={-INF, -INF};
	for(int x:a[n])
	{
		dfs(x, d+l[x]);
		ll t=ans[x];
		for(int i=0;i<2;++i)
			if(h[i]<t) std::swap(h[i], t);
	}
	ckmax(ans[n], h[n!=1]);
	st.upd(1, 1, MV, t[n], -x[n]);
}
int main()
{
	scanf("%d%lld", &N, &T);
	for(int i=1;i<=N;++i) scanf("%d", x+i);
	for(int i=1;i<=N;++i) scanf("%d", t+i);
	for(int i=2;i<=N;++i)
		scanf("%d%d", p+i, l+i), a[p[i]].push_back(i);
	dfs();
	printf("%lld\n", ans[1]);
	return 0;
}