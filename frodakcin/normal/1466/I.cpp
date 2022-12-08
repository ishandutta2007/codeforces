#include <cstdio>
#include <cassert>
#include <deque>
#include <vector>

int N, B;

void out(const std::vector<char>& a, bool pad=0) // strictly greater?
{
	int i=0;
	for(;i<a.size();++i)
		printf("%d", a[i]);
	for(;i<B;++i) printf("%d", pad);
}

bool query(int n, const std::vector<char>& a, bool pad=0)
{
	printf("%d ", n+1);
	out(a, pad);
	printf("\n");
	fflush(stdout);
	char s[5];
	scanf(" %s", s);
	return s[0] == 'y';
}

bool geq(int i, std::vector<char> y) // 0 pad
{
	int j=(int)y.size()-1;
	for(;j>=0 && !y[j];--j);
	if(j==-1) return 1;
	for(;j<y.size();++j)
		y[j] ^= 1;
	return query(i, y, 1);
}

bool gt(int i, const std::vector<char>& y) // 1 pad
{
	return query(i, y, 1);
}

int main()
{
	scanf("%d%d", &N, &B);
	std::deque<int> a;
	for(int i=0;i<N;++i) a.push_back(i);
	std::vector<char> cur;

	for(int it=0;it<N+B-1;++it)
	{
		assert(!a.empty());

		int n = a.front(); a.pop_front();
		while(gt(n, cur))
			a.pop_back(), cur.pop_back();

		if(cur.size() < B)
		{
			a.push_back(n);
			cur.push_back(1);
			if(!geq(n, cur))
				cur.back()=0;
		}

		assert(!a.empty());
	}

	assert(a.size() == 1);
	assert(cur.size() == B);

	printf("0 ");
	out(cur);
	printf("\n");
	fflush(stdout);

	return 0;
}