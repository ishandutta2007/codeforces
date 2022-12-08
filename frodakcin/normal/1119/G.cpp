#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

const int MN = 1e6 + 100;
const int MM = 1e6 + 100;

int N, M;
int hp[MN];

using vi = vector<int>;
#define pb push_back
#define sz size()
vi f;
vi v;
int x[MN];
int group[MN];

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 1;i <= M;i++)
		scanf("%d", hp + i), x[i] = (x[i-1] + hp[i])%N;
	sort(x + 1, x + M);
	x[M] = N; 	//transition from i -> i + 1, so i = M doesnt transition to anywhere and so this value is not important
	for(int i = 0;i < M;i++)
		group[i] = x[i+1] - x[i];
	int c = 0;
	for(int i = 1;i <= M;i++)
		for(;hp[i] > 0;c++)
		{
			if(c == M) c = 0;
			hp[i] -= group[c];
			f.pb(i);
		}
	for(;f.sz%M;)
		f.pb(M);
	printf("%d\n", f.sz/M);
	for(int i = 0;i < M;i++)
		printf("%d%c", group[i], " \n"[i==M-1]);
	for(int i = 0;i < f.sz;i++)
		printf("%d%c", f[i], " \n"[i%M==M-1]);
	return 0;
}