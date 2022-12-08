#include <cstdio>
#include <set>
#include <algorithm>

using ll = long long;
int N, K, M, V;
const int MN = 2e5+10;

std::set<ll> q;
int s[1<<20], v[1<<20];
void upd(int n, int l, int r, int q, int x)
{
	if(r-l>1)
	{
		int m=l+(r-l)/2;
		if(q<m) upd(n<<1, l, m, q, x);
		else upd(n<<1|1, m, r, q, x);
		s[n]=s[n<<1]+s[n<<1|1];
		v[n]=std::max(v[n<<1|1], v[n<<1]+s[n<<1|1]);
	}
	else s[n]+=x, v[n]=s[n]?l+s[n]:0;
}
int main()
{
	scanf("%d%d%d", &N, &K, &M);
	V = N*2+10;
	for(int i=0;i<M;++i)
	{
		int x,y,l;
		scanf("%d%d", &x, &y);
		l = y+(std::abs(x-K));
		ll id=x+(ll)y*N;
		if(q.count(id))
		{
			q.erase(id);
			upd(1, 0, V, l, -1);
		}
		else
		{
			q.insert(id);
			upd(1, 0, V, l, 1);
		}
		printf("%d\n", std::max(0, v[1]-1-N));
	}
	return 0;
}