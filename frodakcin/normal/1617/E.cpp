#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

const int MN = 2e5+10;
const int MV = MN * 30;
const int INF = 0x3f3f3f3f;

int N;
int a[MV], to[MV], nx[MV], hd[MV], X, wh[MV];
std::map<int, int> map;

int nxt(int v) {return v <= 2 ? 0 : (1 << 32 - __builtin_clz(v-1)) - v;}
void adde(int a, int b)
{
	//printf("%d -> %d\n", a, b);
	to[X] = b;
	nx[X] = hd[a];
	hd[a] = X;
	++X;
}

struct info
{
	public:
		int d, n;
		bool operator > (const info& o) const {return d > o.d;}
};
struct cand
{
	public:
		int d, i, j;
		bool operator > (const cand& o) const {return d > o.d;};
} ans;

info dfs(int n)
{
	info r[2] = {{-INF, -1}, {-INF, -1}};
	if(wh[n] != -1)
		r[0] = {0, wh[n]};
	for(int id=hd[n];id!=-1;id=nx[id])
	{
		auto x=dfs(to[id]);
		for(int i=0;i<2;++i)
			if(x > r[i])
				std::swap(x, r[i]);
	}
	ckmax(ans, {r[0].d+r[1].d, r[0].n, r[1].n});
	r[0].d += 1;
	return r[0];
}

int main()
{
	memset(hd, -1, sizeof hd);
	memset(wh, -1, sizeof wh);
	scanf("%d", &N);

	map.insert({0, 0});
	for(int i=0;i<N;++i)
	{
		int a, p=-1;
		scanf("%d", &a);
		for(bool go=1;;a=nxt(a))
		{
			auto it=map.find(a);
			if(it != map.end())
				go = 0;
			else
				it = map.insert({a, map.size()}).first;
			if(p == -1)
				wh[it->second] = i+1;
			else
				adde(it->second, p);
			p = it->second;
			if(!go) break;
		}
	}

	dfs(0);
	printf("%d %d %d\n", ans.i, ans.j, ans.d);
	return 0;
}