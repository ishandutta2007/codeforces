#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

const int MN = 2e5+10;
const int INF = -0xc0c0c0c0;

struct Bound
{
	public:
		int d, v; // <= d is answer v
		Bound(int _d, int _v=-1): d(_d), v(_v) {}
		bool operator < (const Bound& o) const {return d < o.d;}
};

int N, K, dis[MN], f[MN], s[MN], val[MN];
bool r[MN];
std::vector<int> a[MN];
std::queue<int> q;
std::set<Bound> set;

void ins(int d, int v)
{
	//printf("\tWHY %d %d\n", d, v);
	auto it=set.lower_bound(Bound(d));
	if(it != set.end() && it->v >= v) return;
	if(it != set.end() && it->d == d) ++it; // replace this
	for(;it!=set.begin();)
		if((--it)->v <= v)
			it=set.erase(it);
	set.insert(Bound(d,v));
}

int get(int d)
{
	auto it=set.lower_bound(Bound(d));
	return it != set.end() ? it->v : 0;
}

int dfs(int n, int p=0)
{
	s[n]=1;
	for(int x:a[n])
		if(!r[x] && p!=x)
			s[n]+=dfs(x, n);
	return s[n];
}

int get_centroid(int n, int ms, int p=0)
{
	for(int x:a[n])
		if(!r[x] && x!=p && s[x]*2>=ms)
			return get_centroid(x, ms, n);
	return n;
}

void qry(int n, int p, int d)
{
	ckmax(f[n], get(d));
	for(int x:a[n])
		if(x!=p && !r[x])
			qry(x, n, d+1);
}

void upd(int n, int p, int d)
{
	if(dis[n]>d)
		ins(dis[n]-d-1, dis[n]);
	for(int x:a[n])
		if(x!=p && !r[x])
			upd(x, n, d+1);
}

void centroid(int n=1)
{
	n=get_centroid(n, dfs(n));

	if(dis[n]>0) ins(dis[n]-1, dis[n]);
	for(int i=0;i<a[n].size();++i)
		if(!r[a[n][i]])
		{
			qry(a[n][i], n, 1);
			upd(a[n][i], n, 1);
		}
	//printf("\tWHAT %d: %d\n", n, get(0));
	ckmax(f[n], get(0));
	set.clear();

	if(dis[n]>0) ins(dis[n]-1, dis[n]);
	for(int i=(int)a[n].size()-1;i>=0;--i)
		if(!r[a[n][i]])
		{
			qry(a[n][i], n, 1);
			upd(a[n][i], n, 1);
		}
	//printf("\tWHAT %d\n", get(0));
	ckmax(f[n], get(0));
	set.clear();

	r[n]=1;
	for(int x:a[n])
		if(!r[x])
			centroid(x);
}

int main()
{
	memset(dis, -1, sizeof dis);

	scanf("%d", &N);
	for(int i=0,u,v;i+1<N;++i)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	scanf("%d", &K);
	for(int i=0,u;i<K;++i)
	{
		scanf("%d", &u);
		dis[u]=0;
		q.push(u);
	}

	for(int n;!q.empty();)
	{
		n=q.front(); q.pop();
		for(int x:a[n])
			if(!~dis[x])
				dis[x]=dis[n]+1, q.push(x);
	}

	centroid();

	for(int i=1;i<=N;++i)
		printf("%d%c", f[i], " \n"[i==N]);
	return 0;
}