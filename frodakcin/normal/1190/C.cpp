#include <cstdio>
#include <cassert>

using namespace std;

const int MN = 1e5 + 100;
int N, K;
char s[MN];
void w1(void) {printf("tokitsukaze\n");}
void w2(void) {printf("quailty\n");}
void tie(void) {printf("once again\n");}

int n[2][2][MN];//next[0/1][prv/nxt][ind,exc]

bool test(int i, int j) //true if p2 doesnt auto-win
{
	//set i..i+K = j
	int q = (n[!j][1][0]<i|(n[!j][0][N]>=i+K)<<1);
	assert(0<q&&q<=3);
	if(q==2) return n[!j][0][N]-n[!j][1][i+K]+1>=K;
	if(q==1) return n[!j][0][i]-n[!j][1][0]+1>=K;
	return 1;
}

int main(void)
{
	scanf("%d%d %s", &N, &K, s);
	n[0][0][0] = n[0][1][0] = -1;
	for(int i = 0;i < N;i++)
		n[0][0][i+1]=n[0][0][i], n[1][0][i+1]=n[1][0][i], n[s[i]=='1'][0][i+1] = i;
	n[0][1][0] = n[1][1][0] = N;
	for(int i = N-1;i >= 0;i--)
		n[0][1][i]=n[0][1][i+1], n[1][1][i]=n[1][1][i+1], n[s[i]=='1'][1][i] = i;
	if(!~n[0][0][N] || !~n[1][0][N])
		return w1(), 0;
	if(n[0][0][N]-n[0][1][0]+1 <= K || n[1][0][N]-n[1][1][0]+1 <= K)
		return w1(), 0;
	for(int i = 0;i+K <= N;i++)
		for(int j = 0;j < 2;j++)
			if(test(i,j))
				return tie(), 0;
	return w2(), 0;
}