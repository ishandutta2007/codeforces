#include <cstdio>
#include <algorithm>
//#define NDEBUG
#include <cassert>

using namespace std;

const int MK = 17;
const int MN = MK*4;
const int ML = 1e5 + 10;
int K, N;

int grid[2][MK*2];
char tmp[4];
int a[MN];
bool fail()
{
	int inv = 0;
	for(int i = 0;i < N;++i)
		for(int j = i+1;j < N;++j)
			if(a[i] > a[j])
				++inv;
	return inv&1;
}
char ans[ML];
int L;
void append(char s)
{
	ans[L++] = s;
}

void shortcut()//generate all shortcuts
{
	/*
		 Z -> move K spaces right
		 Y -> move K spaces left
		Total: Exhause 2*K <= 30 characters
			*/
	printf("Z ");
	for(int i = 0;i < K;++i) printf("r");
	printf("\nY ");
	for(int i = 0;i < K;++i) printf("l");
	printf("\n");
	/*
		 A -> cycle once (Empty cycles CW, all numbers shift CCW, x maps to x+1
		 B -> cycle twice
		 C -> cycle 4 times
		 ...
		 F -> cycle 32 times
		Total: Exhaust 16 characters
		 */
	printf("A uZZdYY\n");
	for(int i = 1;i <= 5;++i)
		printf("%c %c%c\n", 'A'+i, 'A'+(i-1), 'A'+(i-1));
	
	/*
		 J -> half-cycle
		 K -> move 2K+1 times
		 L -> do entire tri-cycle sequence
		 */
	printf("J ZuYd\n");
	printf("K ");
	for(int i = 2*K+1, j = 0;i > 0;i>>=1, ++j) if(i&1) printf("%c", 'A' + j);
	printf("\n");
	printf("L JJKAJJK\n");
}
void rotate(int i)
{
	for(int j = 0;i;i>>=1, ++j)
		if(i&1)
			append('A' + j);
}
void flip(int node)
{
	assert(2*K < node && node < N);
	for(int i = node, j = 0;j < 2*K;++j, --i)
		std::swap(a[i], a[i-1]);
	rotate(node-K);
	append('J');
	rotate(K+N-node);//this is off-by-1 if node <= 2*K
}
void tri_cycle(int center)//index of B in ABC
{
	assert(0 < center && center < N-1);
	std::swap(a[center], a[center+1]);
	std::swap(a[center], a[center-1]);
	rotate(center<K?center+N-K:center-K);
	append('L');
	rotate(K<center?K+N-center:K-center);
}
int start;
void solve()
{
	L = 0;
	scanf("%d", &K);
	N = K*4+1;
	for(int i = 0;i < 2;++i)
		for(int j = 0;j < K*2+1;++j)
		{
			scanf(" %s", tmp);
			if(tmp[0] == 'E')
				grid[i][j] = 0, start = j<<1|i;
			else
			{
				int x = 0;
				for(int k = 0;tmp[k];++k)
					x = x*10 + (tmp[k]-48);
				grid[i][j] = x;
			}
		}
	//shift E to bottom left
	for(int i = start>>1, j = start&1;i > 0;--i)
		append('l'), std::swap(grid[j][i], grid[j][i-1]);
	if(!(start&1)) std::swap(grid[0][0], grid[1][0]), append('d');

	//modify grid to simpify calculations
	for(int i = 0;i < 2;++i)
		for(int j = 0;j < K*2+1;++j)
			if(grid[i][j] > 2*K+1)
				grid[i][j] = (6*K + 3) - grid[i][j];
	/*
	for(int i = 0;i < 2;++i, printf("\n"))
		for(int j = 0;j < K*2+1;++j)
			printf("%d ", grid[i][j]);
			*/

	//create array
	for(int i = 0;i < K*2+1;++i)
		a[i] = grid[0][i];
	for(int i = K*2;i > 0;--i)
		a[N-i] = grid[1][i];

	if(fail())
		return (void) printf("SURGERY FAILED\n");
	printf("SURGERY COMPLETE\n");
	for(int i = 0;i < N-3;++i)
	{
		for(int j = i;j < N;++j)
			if(a[j] == i+1)
			{
				if(j-i > K*2) flip(j), j -= 2*K;
				for(int k = j-1;k > i;k -= 2)
					tri_cycle(k);
				if(j-i&1)
					tri_cycle(i+1), tri_cycle(i+1);
				break;
			}
	}
	if(a[N-3] == N) tri_cycle(N-2), tri_cycle(N-2);
	else if(a[N-3] == N-1) tri_cycle(N-2);
	for(int i = 0;i < N;++i) assert(a[i] == i+1);
	append('Z');
	append('Z');
	ans[L] = 0;
	printf("%s\n", ans);
	shortcut();
	printf("DONE\n");
}
int T;
int main(void)
{
	scanf("%d", &T);
	for(int i = 1;i <= T;++i)
		solve();
	return 0;
}