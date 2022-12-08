#include <cstdio>
#include <cstring>
#include <array>
#include <vector>

using ar = std::array<int, 4>;

std::vector<ar> f;
ar cur;
char s[20];
int S, a[20], N;
bool ok[20], u[20];

int tvis;
void partition(int i, int j)
{
	if(j==4)
	{
		if(i==S)
			f.push_back(cur);
		return;
	}
	int v=0;
	for(int k=i;k<S;++k)
	{
		v=v*10+s[k];
		if(v>=(1<<8)) break;
		cur[j]=v;
		partition(k+1, j+1);
		if(!v) break;
	}
}
void solve()
{
	int cnt=0;
	for(int i=0;i<S;++i)
	{
		cnt+=!u[s[i]];
		u[s[i]]=1;
	}
	memset(u, 0, sizeof u);
	if(cnt!=N) return;
	partition(0, 0);
}
void brute(int i, int n)
{
	if(i==n)
	{
		S=2*n-1;
		for(int i=1;i<n;++i)
			s[n-1+i]=s[n-1-i];
		solve();

		S=2*n;
		for(int i=0;i<n;++i)
			s[n+i]=s[n-i-1];
		solve();
		return;
	}
	for(int v=0;v<10;++v)
		if(ok[v])
			s[i]=v, brute(i+1, n);
}
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i), ok[a[i]]=1;
	for(int i=2;i<=6;++i)
		brute(0, i);
	//printf("visited %d times\n", tvis);
	printf("%u\n", f.size());
	for(auto x:f) printf("%d.%d.%d.%d\n", x[0], x[1], x[2], x[3]);
	return 0;
}