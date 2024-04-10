#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

using ll = long long;
const int MN = 2e5 + 100;
int N;
struct endpt
{
public:
	int i, r;
	bool operator < (endpt o) const {return r < o.r || !(o.r < r) && i < o.i;}
};
std::vector<endpt> a[MN];
int ib[MN], b[MN], s1 = -1, s2;

const int MS = 1<<19;
ll v[MS];
void upd(int n, int l, int r, int x, ll k)
{
	if(r-l>1)
	{
		int m = l+(r-l)/2;
		if(x < m) upd(n<<1, l, m, x, k);
		else upd(n<<1|1, m, r, x, k);
		v[n] = std::max(v[n<<1], v[n<<1|1]);
	}
	else
		v[n] = k;
}
ll qry(int n, int l, int r, int ql, int qr)
{
	if(ql <= l&&r <= qr) return v[n];
	else
	{
		int m = l+(r-l)/2;ll f = -1;
		if(ql < m) f = std::max(f, qry(n<<1, l, m, ql, qr));
		if(m < qr) f = std::max(f, qry(n<<1|1, m, r, ql, qr));
		return f;
	}
}

std::set<endpt> active;
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, x, y;i < N;++i)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back({i, ++y});
	}
	for(int i = 1;i <= N;++i)
	{
		for(auto x : a[i])
			active.insert(x);
		auto it = active.begin();
		auto y = *it;
		active.erase(it);
		b[y.i] = i;
		ib[i] = y.i;
	}
	//check uniqueness
	memset(v, 0xff, sizeof(v));
	for(int i = 1;i <= N;++i)
		for(auto x : a[i])
		{
			ll z = qry(1, 1, N+1, i, x.r), k = b[x.i];
			//printf("QRY [%d, %d] %d\n", i, x.r, (int)(z>>32));
			if(z>>32 > k)
			{
				s1 = x.i, s2 = (int)(z&0xffffffff);
				goto done;
			}
			upd(1, 1, N+1, k, (ll)x.r<<32|x.i);
			//printf("UPD: %d %d\n", k, x.r);
		}
done:
	if(!~s1)
	{
		printf("YES\n");
		for(int i = 0;i < N;++i)
			printf("%d%c", b[i], " \n"[i+1==N]);
	}
	else
	{
		printf("NO\n");
		for(int i = 0;i < N;++i)
			printf("%d%c", b[i], " \n"[i+1==N]);
		std::swap(b[s1], b[s2]);
		for(int i = 0;i < N;++i)
			printf("%d%c", b[i], " \n"[i+1==N]);
	}
	return 0;
}