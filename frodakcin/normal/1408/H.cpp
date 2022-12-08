#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 5e5+10;

int T, N, M, a[MN], z[MN], ml[MN], mr[MN];
std::vector<int> q[MN];
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

void solve()
{
	memset(ml+1, 0, N*sizeof*ml);
	memset(mr+1, 0, N*sizeof*mr);
	scanf("%d", &N), M=0;
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i);
		if(a[i]==0)
			z[M++]=i;
	}
	if(M<2)
		return printf("0\n"), void();
	int lb=z[M/2-1], rb=z[(M+1)/2];
	for(int i=0,c=0;i<rb;++i)
		if(!a[i])
			c=std::min(c+1, M/2);
		else
			ckmax(ml[a[i]], c);
	for(int i=N-1,c=0;i>lb;--i)
		if(!a[i])
			c=std::min(c+1, M/2);
		else
			ckmax(mr[a[i]], c);
	for(int i=1;i<=N;++i)
		if(ml[i]||mr[i])
			q[ml[i]].push_back(mr[i]);
	int f=0;
	while(pq.size()) pq.pop();
	for(int i=M/2;i>=0;--i)
	{
		for(auto x:q[i])
			pq.push(x);
		q[i].clear();
		if(i && !pq.empty())
			pq.pop(), ++f;
	}
	for(int i=1;i<=M/2;++i)
	{
		for(;pq.size() && pq.top() < i;) pq.pop();
		if(pq.empty())
			break;
		else
			pq.pop(), ++f;
	}
	printf("%d\n", std::min(f, M/2));
}

int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}