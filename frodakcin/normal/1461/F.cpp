#include <cstdio>
#include <cassert>
#include <vector>
#include <stack>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 1e5+10;
const int INF = 1e9;

int N, a[MN], S;
char s[5];
bool add, sub, mul;

struct range
{
	public:
		int l,r;
};

int prod(int a, int b)
{
	if(a>INF/b) return INF;
	return a*b;
}

void segment(std::vector<int> v)
{
	assert(add && mul);
	int N=v.size();

	std::vector<int> p(N+1), g;
	int tot=1;
	for(int i=0;i<N;++i)
	{
		p[i+1]=p[i]+v[i];
		if(v[i]>1)
			g.push_back(i);
		tot = prod(tot, v[i]);
	}

	if(g.empty())
	{
		for(int i=0;i<N;++i)
		{
			printf("%d", v[i]);
			if(i+1<N)
				printf("+");
		}
	}
	else if(tot==INF) // merge all [tot cannot exceed inf]
		for(int i=0;i<N;++i)
		{
			printf("%d", v[i]);
			if(i+1<N)
			{
				if(i >= g.front() && i < g.back()) printf("*");
				else printf("+");
			}
		}
	else // selectively merge; why is this so high effort ?!
	{
		assert(g.size() < 32);
		assert(!g.empty());
		std::vector<int> dp(g.size()), pr(g.size());

		for(int i=0;i<g.size();++i)
		{
			dp[i]=-1;
			int val=v[g[i]];
			for(int j=i-1;j>=0;--j)
			{
				if(ckmax(dp[i], val+dp[j] +p[g[j+1]]-p[g[j]+1]))
					pr[i]=j+1;
				val *= v[g[j]];
			}
			if(ckmax(dp[i], val+p[g[0]]))
				pr[i]=0;
		}
		//printf("IDEAL: %d\n", dp.back());

		std::stack<range> s;
		for(int i=g.size()-1;i>=0;)
		{
			s.push({g[pr[i]], g[i]});
			i=pr[i]-1;
		}

		for(int i=0;i<N;++i)
		{
			printf("%d", v[i]);
			if(!s.empty() && i >= s.top().r) s.pop();
			if(i+1<N)
			{
				if(!s.empty() && s.top().l <= i && i < s.top().r)
					printf("*");
				else
					printf("+");
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d", a+i);
	scanf(" %s", s);
	for(;s[S];++S)
	{
		add |= s[S]=='+';
		sub |= s[S]=='-';
		mul |= s[S]=='*';
	}
	if(S==1)
		for(int i=0;i<N;++i)
			printf("%d%c", a[i], i+1==N?'\n':s[0]);
	else if(add && mul) // or all 3
	{
		//cancer
		for(int i=0,j;i<N;i=j)
		{
			std::vector<int> v;
			for(j=i;j<N && a[j]>0;++j)
				v.push_back(a[j]);

			if(!v.empty()) segment(v);
			else printf("0"), ++j;

			if(j<N) printf("+");
			else printf("\n");
		}
	}
	else if(add) // add sub
		for(int i=0;i<N;++i)
			printf("%d%c", a[i], "+\n"[i+1==N]);
	else // sub mul
	{
		bool s0=0;
		printf("%d", a[0]);
		s0=a[0]==0;
		for(int i=1;i<N;++i)
		{
			if(s0) printf("*");
			else if(a[i]==0)
			{
				printf("-");
				s0=1;
			}
			else printf("*");
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}