#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>
#include <functional>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

mt19937 rng;

ll MAX = 1e18;
const int MN = 1e3 + 100;

int get_rand(int x)
{
	return static_cast<int>(tl(rng())*x/(tl(rng.max())-rng.min()+1));
}

int N; ll L, E;
array<ll, 2> ans[MN];

ll get(int f, ll x)
{
	printf("? %d %lld\n", f, x);
	fflush(stdout);
	ll r; scanf("%lld", &r); return r;
}
ll loc(int f, ll v, ll l = 0, ll r = MAX)
{
	r++;
	ll m;
	while(r-l>1)
	{
		m = l+(r-l>>1);
		if(get(f, m) > v) r = m;
		else l = m;
	}
	return l;
}
void solve(vector<int> &v, int l, int r, ll lp, ll rp)
{
	if(v.size() == 1)
		return ans[v[0]] = {lp, rp}, void();
	random_shuffle(v.begin(), v.end(), get_rand);
	int m = l+(r-l>>1); ll mp;
	function<ll(vector<int>&, int)> kth_element = [&](vector<int>& x, int k)
	{
		vector<int> a, b, c;
		b.push_back(x.back());
		ll t = loc(x.back(), m*E, lp, rp);
		for(x.pop_back();!x.empty();x.pop_back())
		{
			ll q = get(x.back(), t);
			if(m*E < q) a.push_back(x.back());
			else if(q < m*E) c.push_back(x.back());
			else b.push_back(x.back());
		}
		if(k < a.size()) t = kth_element(a, k);
		else if(a.size() + b.size() <= k) t = kth_element(c, k-a.size()-b.size());
		for(int i : a) x.push_back(i);
		for(int i : b) x.push_back(i);
		for(int i : c) x.push_back(i);
		return t;
	};
	mp = kth_element(v, m-l);
	//for(int i : v) printf("%d ", i); printf("(%d %d)\n", m, m-l);
	vector<int> L, R;
	for(int i = 0;i < m-l;i++) L.push_back(v[i]);
	for(int i = m-l;i < r-l;i++) R.push_back(v[i]);
	solve(L, l, m, lp, mp);
	solve(R, m, r, mp, rp);
}
int main(void)
{
	srand(clock());
	scanf("%d%lld", &N, &L);
	E = L/N;
	vector<int> a;
	for(int i = 1;i <= N;i++)
		a.push_back(i);
	solve(a, 0, N, 0, MAX);
	printf("!\n");
	for(int i = 1;i <= N;i++)
		printf("%lld %lld\n", ans[i][0], ans[i][1]);
	fflush(stdout);
	return 0;
}