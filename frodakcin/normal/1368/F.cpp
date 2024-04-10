#include <cstdio>
#include <vector>

const int MN = 1e3+10;
int N, B, K;
bool u[MN], on[MN], ok;
std::vector<int> g, q;

int main(void)
{
	scanf("%d", &N);
	for(int k=2;k<N;++k)
	{
		int v=(k-1)*N/k - (k-1);
		if(v>B)
			B=v, K=k;
	}
	if(!K) return printf("0\n"), 0;

	for(int i=0;i+1<N;++i)
		if(i%K < K-1)
			u[i]=1, g.push_back(i);
	for(int rem;!ok;)
	{
		q.clear();
		for(int i=0;i<g.size();++i)
		{
			if(i+1==g.size()) ok=1;
			if(!on[g[i]]) q.push_back(g[i]);
			if(q.size()==K) break;
		}
		printf("%u\n", q.size());
		for(int i=0;i<q.size();++i)
			printf("%d%c", q[i]+1, " \n"[i+1==q.size()]), on[q[i]]=1;
		fflush(stdout);

		scanf("%d", &rem);
		if(!~rem) return 0;
		--rem;
		for(int i=0;i<q.size();++i)
		{
			on[rem]=0;
			if(++rem == N) rem=0;
		}
	}
	printf("0\n");
	return 0;
}