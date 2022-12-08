#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 1e5+10;

int N, K, ctr[26];
char s[MN];

void solve()
{
	memset(ctr, 0, sizeof ctr);
	scanf("%d%d", &N, &K);
	scanf(" %s", s);
	if(N%K!=0)
		return (void) printf("-1\n");
	for(int i=0;i<N;++i) ++ctr[s[i] -= 'a'];

	bool ok=1;
	for(int i=0;ok && i<26;++i)
		if(ctr[i]%K)
			ok=0;
	if(ok)
	{
		for(int i=0;i<N;++i) s[i]+='a';
		printf("%s\n", s);
		return;
	}

	for(int i=N-1;i>=0;--i) // match prefix of length i
	{
		--ctr[s[i]];
		if(s[i] == 25) continue; // can't place anything here

		//test
		int need = 0;
		char maxneed = -1;
		for(int j=0, t;j<26;++j)
			if(t=ctr[j]%K)
			{
				ckmax<char>(maxneed, j);
				need += K-t;
			}

		int wild = N-i-1; // i prefix, 1 >s[i], N-i-1 wildcards
		if(need > wild+1 || maxneed <= s[i] && need > wild)
			continue;

		//found answer
		{
			std::vector<char> x;
			for(int j=0, t;j<26;++j)
				if(t=ctr[j]%K)
					for(int k=0;k<K-t;++k) x.push_back(j);

			//printf("%d: \n", i);
			if(ctr[s[i]+1]%K == 0 && x.size() < N-i) // we can give s[i] a better value
				for(int j=0;j<K;++j) x.push_back(s[i]+1);

			// pad with 'a's
			x.resize(N-i, 0);

			std::sort(x.begin(), x.end());
			auto it=std::upper_bound(x.begin(), x.end(), s[i]);
			assert(it != x.end());

			std::rotate(x.begin(), it, std::next(it));
			for(int j=0;j<N-i;++j)
				s[i+j] = x[j];

			for(int j=0;j<N;++j)
				s[j] += 'a';
			printf("%s\n", s);
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}