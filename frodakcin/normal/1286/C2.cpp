#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>

const int MN = 1e2 + 10;
int N;

char f[MN];
void set(int v, int k)
{
	char z = k+'a';
	assert(!f[v] || f[v] == z);
	f[v] = z;
}

bool v[MN];
struct E
{
public:
	int n;
	int w;
};
std::vector<E> a[MN];
void adde(int x, int y, int w)
{
	a[x].push_back({y, w});
	a[y].push_back({x, w});
}

char s[MN];

int cnt[MN][26];
int act[26];//ual
int exp[26];//ected difference
void query(int l, int r)
{
	memset(cnt, 0, sizeof(cnt));
	memset(act, 0, sizeof(act));
	memset(exp, 0, sizeof(exp));

	printf("? %d %d\n", l+1, r);
	fflush(stdout);
	for(int i = 0, j = (r-l)*(r-l+1)/2, S;i < j;++i)
	{
		scanf(" %s", s);
		for(S=0;s[S];++S);
		for(int k = 0;k < S;++k)
			++cnt[S][s[k]-'a'];
	}

	for(int i = 1, j = (r-l)/2;i <= j;++i)
	{
		int x = 0, y = 0;
		for(int k = 0;k < 26;++k)
			for(int l = (cnt[1][k]*(i+1)-exp[k]) - cnt[i+1][k];l;--l)
			{
				assert(l >= 0);
				x = k, std::swap(x, y);
			}
		if(x == y)
			set(l+i-1, x), set(r-i, x);
		else
			adde(l+i-1, r-i, x|y<<8);

		++act[x], ++act[y];
		++exp[x], ++exp[y];
		for(int k = 0;k < 26;++k)
			exp[k] += act[k];
	}
	if(r-l&1)
		for(int i = 0;i < 26;++i)
			if(cnt[1][i] - act[i] == 1)
				set((r+l)/2, i);
}

void dfs(int n)
{
	if(v[n]) return;
	v[n] = 1;
	for(E x : a[n])
	{
		//if(v[x.n]) continue;
		int t = f[n]-'a' == (x.w&(1<<8)-1) ? x.w>>8 : x.w&(1<<8)-1;
		set(x.n, t);
		dfs(x.n);
	}
}

int fs[26];
int main(void)
{
	scanf("%d", &N);
	if(N <= 3)
	{
		for(int i = 0;i < N;++i)
		{
			printf("? %d %d\n", i+1, i+1);
			fflush(stdout);
			scanf(" %c", f+i);
		}
		printf("! %s\n", f);
		return 0;
	}
	if(N&1)
	{
		query(0, N);
		for(int i = 0;i < 26;++i) fs[i] = cnt[1][i];
		query(1, 1+N/2);
		for(int i = 0;i < 26;++i) fs[i] -= cnt[1][i];
		query(N-N/2, N);
		for(int i = 0;i < 26;++i) fs[i] -= cnt[1][i];
		for(int i = 0;i < 26;++i)
		{
			assert(fs[i] == 1 || fs[i] == 0);
			if(fs[i])
				set(0, i);
		}
	}
	else
	{
		query(0, N/2);
		for(int i = 0;i < 26;++i) fs[i] = cnt[1][i];
		query(N/2, N);
		for(int i = 0;i < 26;++i) fs[i] += cnt[1][i];
		query(1, N);
		for(int i = 0;i < 26;++i) fs[i] -= cnt[1][i];
		for(int i = 0;i < 26;++i)
		{
			assert(fs[i] == 1 || fs[i] == 0);
			if(fs[i])
				set(0, i);
		}
	}
	for(int i = 0;i < N;++i)
		if(f[i] && !v[i])
			dfs(i);
	printf("! %s\n", f);
	return 0;
}