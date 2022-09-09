#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

const int limc = 20 + 5;
const int limx = 500 + 5;

int n;
char s[MAXN];

int f[MAXN][limc * 2 + 5][limx * 2 + 5][2];
int gao(int pos,int c,int x,int delta)
{
	if(pos == n) return abs(c * 10 + s[pos] - x);
	if(c < -limc || c > limc || x < -limx || x > limx) return inf;
	int &res = f[pos][c + limc][x + limx][delta == 1];
	if(~res) return res;
	
	res = inf;
	chk_min(res, gao(pos, c, x + delta, delta) + n-pos+1);
	chk_min(res, gao(pos+1, c * 10 + s[pos] - x, x, 1));
	chk_min(res, gao(pos+1, c * 10 + s[pos] - x, x, -1));
	return res;
}

int main(void)
{
	scanf("%s",s+2);
	n = strlen(s+2) + 1;
	for(int i=2; i<=n; ++i) s[i] -= '0';
	
	memset(f,-1,sizeof(f));
	printf("%d",gao(1,0,0,1));
	return 0;
}