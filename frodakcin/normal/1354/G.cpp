#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>

char res[10];
int T, N, K;
std::vector<int> a, r;
std::mt19937 rng;

int main(void)
{
	rng = std::mt19937(clock());
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d%d", &N, &K);
		for(int i=1;i<=N;++i)
			a.push_back(i);
		std::shuffle(a.begin(), a.end(), rng);
		int r0=a[0];
		for(int i=std::min(30, (int)a.size()-1);i>1;--i)
		{
			printf("? %d %d\n%d\n%d\n", 1, 1, r0, a[i]);
			fflush(stdout);
			scanf(" %s", res);
			if(res[0]=='W') exit(0);
			if(res[0]=='S')
				r0=a[i];
		}

		r.push_back(r0);//rock collection
		a.clear();
		for(int i=1;i<=N;++i)
			if(i!=r[0])
				a.push_back(i);
		for(;r.size()<a.size();)
		{
			int R=r.size();
			printf("? %d %d\n", R, R);
			for(int i=0;i<R;++i) printf("%d%c", r[i], " \n"[i+1==R]);
			for(int i=0;i<R;++i) printf("%d%c", a[i], " \n"[i+1==R]);
			fflush(stdout);
			scanf(" %s", res);
			if(res[0]=='W') exit(0);
			assert(res[0] != 'S');
			if(res[0] == 'E')
			{
				for(int i=0;i<R;++i)
					r.push_back(a[i]);
				a.erase(a.begin(), a.begin()+R);
			}
			else
			{
				a.resize(r.size());
				break;
			}
		}

		{
			int l=0,r=a.size(),m,S;
			for(;r-l>1;)
			{
				m=l+(r-l)/2, S=m-l;
				printf("? %d %d\n", S, S);
				for(int i=0;i<S;++i) printf("%d%c", ::r[i], " \n"[i+1==S]);
				for(int i=l;i<m;++i) printf("%d%c", a[i], " \n"[i+1==m]);
				fflush(stdout);
				scanf(" %s", res);
				if(res[0]=='W') exit(0);
				assert(res[0] != 'S');
				if(res[0]=='F')
					r=m;
				else
					l=m;
			}
			printf("! %d\n", a[l]);
			fflush(stdout);
		}
		r.clear(); a.clear();
	}
	return 0;
}