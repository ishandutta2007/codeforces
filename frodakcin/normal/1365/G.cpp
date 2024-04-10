#include <cstdio>
#include <vector>

const int MN = 1e3+10;
using ll = long long;

std::vector<int> a[MN], q[13], b;
int N, c;
ll v[13];
void brute(int n, int x)
{
	if(n==6)
		return a[c++]=b, void();
	for(;x+(6-n)<=13;++x)
	{
		b.push_back(x);
		brute(n+1, x+1);
		b.pop_back();
		if(c==N)
			break;
	}
}
	

int main(void)
{
	scanf("%d", &N);
	brute(0, 0);
	for(int i=0;i<N;++i)
		for(auto x:a[i])
			q[x].push_back(i);
	for(int i=0;i<13;++i)
	{
		if(q[i].empty()) continue;
		printf("? %u", q[i].size());
		for(auto x:q[i]) printf(" %d", x+1);
		printf("\n");
		fflush(stdout);
		scanf("%lld", v+i);
		if(!~v[i]) return 0;
	}
	printf("!");
	for(int i=0,j,k;i<N;++i)
	{
		ll x=0;
		for(j=k=0;j<13;++j)
			if(k<6&&a[i][k]==j)
				++k;
			else
				x|=v[j];
		printf(" %lld", x);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}