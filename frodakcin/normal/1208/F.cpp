#include <cstdio>
#include <vector>

template<class T> bool mx(T* a, T b) {return *a<b?*a=b,1:0;}

const int MN = 1e6 + 100;
const int K = 21, A = (1<<K)-1;

struct S
{
public:
	int v[2];
	S(int a = -1, int b = -1) {v[0] = a, v[1] = b;}
	void operator += (int x)
	{
		for(int i = 0;i < 2;++i) if(x > v[i]) std::swap(x, v[i]);
	}
	void operator += (S o)
	{
		for(int i = 0;i < 2 && ~o.v[i];++i)
			for(int j = 0, t = o.v[i];j < 2;++j)
				if(t > v[j])
					std::swap(t, v[j]);
	}
};
S dp[1<<K];
int a[MN], N, f;
std::vector<int> u[MN];
bool v[1<<K];
int test(int m)
{
	int n = 0;
	for(int i = K-1;i >= 0;i--)
		if(m&1<<i&&v[n|1<<i])
			n|=1<<i;
	return n;
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%d", a+i), dp[a[i]]+=i;
	for(int i = 0;i < K;i++)
		for(int j = 0;j < 1<<K;++j)
			if(!(j>>i&1))
				dp[j] += dp[j|1<<i];
	for(int i = 0, t;i < 1<<K;++i)
		if(~(t=dp[i].v[1]))
			u[t].push_back(i);
	for(int i = N-1;i >= 0;i--)
	{
		if(i < N-2)
			mx(&f, a[i] + test(A^a[i]));
		for(int x : u[i])
			v[x] = 1;
	}
	printf("%d\n", f);
	return 0;
}