#include <cstdio>
#include <vector>
#include <functional>
#include <queue>

const int MN = 1e3 + 10;

std::vector<int> a[MN];
std::vector<int> b[MN];
int N;
int p[MN], v[MN], s[MN];

int dfs(int n)
{
	s[n]=1;
	for(int x : a[n])
		if(p[n]!=x)
			p[x] = n, s[n]+=dfs(x);
	return s[n];
}
int get_centroid(int n, int ms)
{
	for(int x : a[n])
		if(p[n]!=x&&s[x]*2>ms)
			return get_centroid(x, ms);
	return n;
}
int A, B;

void dfs3(int n, int p)
{
	v[n] = B += A+1;
	printf("%d %d %d\n", p, n, v[n]-v[p]);
	for(int x : a[n])
		if(x != p)
			dfs3(x, n);
}
void dfs2(int n, int p)
{
	dfs3(n, p);
	for(int x : b[n])
		dfs2(x, p);
}

int main(void)
{
	scanf("%d", &N);
	if(N==1)
		return 0;
	for(int i = 0, a, b;i+1 < N;i++)
		scanf("%d%d", &a, &b), ::a[a].push_back(b), ::a[b].push_back(a);
	if(N==2)
		return printf("1 2 1\n"), 0;
	int n = get_centroid(1, dfs(1));
	p[n] = 0, dfs(n);
	std::priority_queue<int, std::vector<int>, std::function<bool(int, int)> > q([](int a, int b){return s[a]>s[b];});
	for(int x : a[n])
		q.push(x);
	for(int a, b;q.size()>2;)
	{
		a = q.top(), q.pop(), b = q.top(), q.pop();
		s[a]+=s[b];
		::b[a].push_back(b);
		q.push(a);
	}
	dfs2(q.top(), n), q.pop(), A = B, B = 0, dfs2(q.top(), n), q.pop();
	return 0;
}