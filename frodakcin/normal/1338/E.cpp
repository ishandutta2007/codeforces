#include <cstdio>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <vector>

using ll = long long;
const int MN = 1 << 13;
int N;
std::bitset<MN> a[MN];
std::vector<int> Pn, Qn;
int ind[MN];
int x;
std::bitset<MN> P, Q;
int inV[MN];

ll ans = 0;
char instr[MN/4];
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
	{
		scanf(" %s", instr);
		for(int j = 0;j < N/4;++j)
		{
			char c = instr[j];
			c = c < 'A' ? c - '0' : 10 + (c - 'A');
			a[i][j*4]   = c&8;
			a[i][j*4+1] = c&4;
			a[i][j*4+2] = c&2;
			a[i][j*4+3] = c&1;
		}
	}
	for(int i = 0;i < N;++i)
		for(int j = 0;j < N;++j)
			if(a[i][j])
				++ind[j];
	x = 0;
	for(int i = 1;i < N;++i)
		if(ind[i] > ind[x])
			x = i;
	//printf("X: %d\n", x+1);
	for(int i = 0;i < N;++i)
		if(i == x || a[i][x])
			Pn.push_back(i), P[i] = 1;
		else
			Qn.push_back(i), Q[i] = 1;
	std::sort(Pn.begin(), Pn.end(), [](int x, int y){return a[x][y];});
	std::sort(Qn.begin(), Qn.end(), [](int x, int y){return a[x][y];});

	//printf("P: "); for(int i = 0;i < Pn.size();++i) printf("%d%c", Pn[i]+1, " \n"[i+1==Pn.size()]);
	//printf("Q: "); for(int i = 0;i < Qn.size();++i) printf("%d%c", Qn[i]+1, " \n"[i+1==Qn.size()]);

	int pr = 0;
	for(;pr < Pn.size();++pr)
		if(ind[Pn[pr]] == pr)
			ans += 614LL*N*(N-pr-1) + Qn.size();
		else
			break;
	//printf("PR: %d\n", pr);
	
	ans += Qn.size() * (Qn.size()-1) + Pn.size() * (Pn.size()-1) >> 1;
	ans += Qn.size() * (Pn.size() - pr) * 3;
	for(int i = 0;i < Qn.size();++i) inV[Qn[i]] = (a[Qn[i]] & P).count();//N^2/64
	for(int i = 0;i < Pn.size();++i) inV[Pn[i]] = (a[Pn[i]] & Q).count();//N^2/64
	std::sort(Qn.begin(), Qn.end(), [](int x, int y){return inV[x] < inV[y];});//N log N
	std::sort(Pn.begin() + pr, Pn.end(), [](int x, int y){return inV[x] < inV[y];});//N log N
	for(int i = 0, j;i < Qn.size();i=j)
	{
		for(j=i;j < Qn.size() && inV[Qn[i]] == inV[Qn[j]];++j)
			ans += (j-i)*3;
		ans += (Qn.size()-j) * (j-i) * 2;
	}
	for(int i = pr, j;i < Pn.size();i=j)
	{
		for(j=i;j < Pn.size() && inV[Pn[i]] == inV[Pn[j]];++j)
			ans += (j-i)*3;
		ans += (Pn.size()-j)*(j-i)*2;
	}
	printf("%lld\n", ans);
	return 0;
}