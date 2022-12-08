#include <cstdio>
#include <vector>

const int MN = 110;
const int MM = 25;

int N, M, W, cur, loc[MN];
bool inc;
std::vector<int> rem;

int query(int r, int d)
{
	printf("? %d %d\n", r, d);
	fflush(stdout);
	int a;
	scanf("%d", &a);
	std::swap(cur, a);
	return cur-a;
	// delta. +1 if new laser visible, 0 is same, -1 if new laser covered
}

int main()
{
	scanf("%d%d", &N, &M), W=N*M;
	query(0, 1);
	//align: (at most NM, 2000)
	for(;;)
		if(query(0, 1) > 0)
			inc=1;
		else if(inc)
			break;
	query(0, -1);

	for(int i=1;i<N;++i)
		rem.push_back(i);
	//run through
	for(int i=0;i<W;++i)
	{
		if(query(0, 1) > 0) // need to shift more
		{
			inc = 1;
			continue;
		}
		else if(!inc)
			continue;
		if(rem.empty())
			continue;
		query(0, -1);

		int l=0, r=rem.size();
		bool out=0;
		for(;r-l>1;)
		{
			int m=l+(r-l)/2;
			if(!out)
				for(int j=m;j<r;++j)
					query(rem[j], -1);
			else
				for(int j=l;j<m;++j)
					query(rem[j], 1);
			if(query(0, -1) < 0)
			{
				r = m;
				out=0;
			}
			else
			{
				l = m;
				out=1;
			}
			query(0, 1);
		}

		int x = rem[l];
		for(int j=out-1;j<M;++j)
			query(x, -1);
		loc[x] = i-M-1;
		rem.erase(rem.begin()+l);

		--i;
		query(0, -1);
		inc = query(0, 1)>0;
	}

	printf("!");
	for(int i=1;i<N;++i)
	{
		int v = loc[i];
		if(v<0) v += W;
		printf(" %d", v);
	}
	printf("\n");
	//for(auto x:rings) printf("%d\n", x);
	fflush(stdout);
	return 0;
}