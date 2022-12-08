//Fixed line 138.....
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <chrono>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return a>b?a=b,1:0;}

typedef std::chrono::high_resolution_clock::time_point time_point;

const int MN = 1e4+10, MM = 1e4+10, MK = 10, MQ = 2e5+10, INF = 50*MM;

int N,M,K,Q,ex[MN], cap[MM*2], h[MN], hd[MN], nx[MM*2], to[MM*2], X, cur[MN], tot, mask, ans[1<<MK], sm[1<<MK], vis[MN], V, buffer[(int)3e7], *flow=buffer, *buf=buffer;
bool done[1<<MK];
time_point timer;
struct Event
{
	public:
		int m, time, *flow;
		Event(int m=-1, int t=-1, int *f=nullptr) : m(m), time(t), flow(f) {}
		bool operator < (const Event& o) const {return time < o.time;}
};

void tick() {timer = std::chrono::high_resolution_clock::now();}

int tock() {return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-timer).count();}

void add1(int a, int b, int f)
{
	nx[X]=hd[a], hd[a]=X;
	cap[X]=f, to[X]=b;
	++X;
}

void adde(int a, int b, int f)
{
	add1(a,b,f);
	add1(b,a,0);
}

int saturate()
{
	std::queue<int> q;
	auto push=[&](int n, int i)
	{
		int f=std::min(ex[n], cap[i]-flow[i]), x=to[i];
		flow[i]+=f, flow[i^1]-=f;
		ex[n]-=f, ex[x]+=f;
		if(ex[x]==f) q.push(x);
	};
	auto relabel=[&](int n)
	{
		int v=N*2+10;
		for(int i=hd[n];~i;i=nx[i])
			if(cap[i]-flow[i]>0)
				ckmin(v, h[to[i]]);
		h[n]=v+1;
	};
	h[1]=N;
	memcpy(cur, hd, sizeof hd);
	ex[1]=INF;
	for(int i=hd[1];~i;i=nx[i])
		if(cap[i]-flow[i]>0)
			push(1, i);
	for(int n;!q.empty();)
	{
		n=q.front(); q.pop();
		if(n==1||n==N) continue;
		for(int& i=cur[n];;)
			if(~i)
			{
				if(cap[i]-flow[i]>0 && h[to[i]] == h[n]-1)
				{
					push(n, i);
					if(ex[n]==0) break;
				}
				i=nx[i];
			}
			else
			{
				relabel(n);
				i=hd[n];
			}
	}
	return INF-ex[1];
}

int dfs(int n, int f)
{
	vis[n]=V;
	if(n==N)
		return f;
	for(int &i=cur[n];~i;i=nx[i])
		if(cap[i]-flow[i]>0 && vis[to[i]]<V)
		{
			int v=dfs(to[i], std::min(f, cap[i]-flow[i]));
			if(v>0)
				return flow[i]+=v, flow[i^1]-=v, v;
		}
	return 0;
}

int resaturate()
{
	int x=0;
	for(bool ok=1;ok;)
	{
		ok=0;
		memcpy(cur+1, hd+1, N*sizeof*hd);
		for(int v;;)
		{
			++V;
			v=dfs(1, 25);
			if(!v) break;
			x+=v;
			ok=1;
		}
	}
	return x;
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	memset(hd, -1, sizeof hd);
	for(int i=0,u,v,w;i<M;++i)
		scanf("%d%d%d", &u, &v, &w), adde(u,v,w);
	tot = saturate();
	ans[(1<<K)-1]=tot;
	for(int i=0;i<K;++i)
		flow[i*2]=cap[i*2]=25;
	std::priority_queue<Event> q;
	q.push({(1<<K)-1, 0, flow});
	for(;!q.empty();)
	{
		auto n=q.top(); q.pop();
		for(int i=0;i<K;++i)
			if(n.m&1<<i)
			{
				if(done[n.m^1<<i]) continue;
				auto x=Event(n.m^1<<i, -1, buf+=2*M);
				memcpy(buf, n.flow, 2*M*sizeof*buf);
				x.flow[i*2]=0;
				flow = x.flow;
				tick();
				ans[x.m] = ans[n.m]+resaturate();
				x.time=tock();
				done[x.m]=1;
				q.push(x);
			}
	}
	for(int i=0;i<Q;++i)
	{
		for(int j=0;j<K;++j)
			scanf("%d", sm+(1<<j));
		int fv=ans[0];
		for(int j=1,k;j<1<<K;++j)
		{
			k=j&j-1;
			sm[j]=sm[k]+sm[j^k];
			ckmin(fv, sm[j]+ans[j]);
		}
		printf("%d\n", fv);
	}
	return 0;
}