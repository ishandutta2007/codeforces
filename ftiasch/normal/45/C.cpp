// School Team Contest #3
// Problem C -- Dancing Lessons
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 200001

using namespace std;

struct Data
{
	int u, v, w;
	bool operator < (Data &other)
	{
		if(w == other.w)
			return u < other.u;
		return w < other.w;
	}
};

int n, a[N], l[N], r[N], m = 0, au[N], av[N], size = 0;
bool b[N], v[N];
char bf[N];
Data h[N];

void list_delete(int i)
{
	r[l[i]] = r[i];
	l[r[i]] = l[i];
}

void heap_insert(int u, int v, int w)
{
	int i = ++ size;
	h[i].u = u, h[i].v = v, h[i].w = w;
	while(i > 1)
	{
		if(h[i >> 1] < h[i])
			break;
		swap(h[i >> 1], h[i]);
		i = i >> 1;
	}
}

void heap_delete()
{
	h[1] = h[size --];
	int i = 1;
	while(i <= size)
	{
		int j = i;
		if(i + i <= size && h[i + i] < h[j])
			j = i + i;
		if(i + i + 1 <= size && h[i + i + 1] < h[j])
			j = i + i + 1;
		if(i == j)
			break;
		swap(h[i], h[j]);
		i = j;
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", bf);
	for(int i = 0; i != n; ++ i)
		b[i + 1] = bf[i] == 'B';
	for(int i = 1; i <= n; ++ i)
		scanf("%d", a + i);
	
	for(int i = 1; i <= n; ++ i)
		l[i] = i - 1, r[i] = i + 1;
	l[1] = r[n] = 0;
	
	memset(v, 0, sizeof(v));

	for(int i = 1; i < n; ++ i)
		if(b[i] != b[i + 1])
			heap_insert(i, i + 1, abs(a[i] - a[i + 1]));

	while(size)
	{
		Data temp = h[1];
		heap_delete();
		if(v[temp.u] || v[temp.v])
			continue;

		m ++;
		au[m] = temp.u, av[m] = temp.v;
		v[temp.u] = v[temp.v] = true;

		list_delete(temp.u);
		list_delete(temp.v);
		
		int i = l[temp.u], j = r[temp.v];
		if(i && j && b[i] != b[j])
			heap_insert(i, j, abs(a[i] - a[j]));
	}

	printf("%d\n", m);
	for(int i = 1; i <= m; ++ i)
		printf("%d %d\n", au[i], av[i]);
	return 0;
}