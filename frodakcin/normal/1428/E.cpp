#include <cstdio>
#include <queue>

using ll = long long;

const int MN = 1e5+10;

int N, K, a[MN];
ll ans;

struct info
{
	public:
		int a, v;
		ll b;
		ll val()
		{
			int k=a%v, d=a/v;
			ll f=0;
			f += (ll)(v-k)*d*d;
			f += (ll)k*(d+1)*(d+1);
			return f;
		}
		info(int _a=0, int _v=1) : a(_a), v(_v)
	{
		b=0;
		b += val();
		++v;
		b -= val();
	}
		bool operator < (const info& o) const
		{
			return b < o.b;
		}
};
std::priority_queue<info> q;

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i);
		ans += (ll)a[i]*a[i];
		q.push({a[i], 1});
	}
	for(int i=N;i<K;++i)
	{
		info x=q.top(); q.pop();
		ans -= x.b;
		q.push({x.a, x.v});
	}
	printf("%lld\n", ans);
	return 0;
}