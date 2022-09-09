#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

inline int get_num1(int x)
{
	int res = 0;
	while(x) ++res, x ^= lowbit(x);
	return res;
}

char s[10][10];

inline bool check(int mask1,int mask2)
{
	for(int i=1; i<=8; ++i)
		for(int j=1; j<=8; ++j)
			if((s[i][j] == 'B') != (bdig(mask1, i-1) | bdig(mask2, j-1)))
				return 0;
	return 1;
}

int main(void)
{
	for(int i=1; i<=8; ++i) scanf("%s",s[i]+1);
	
	int all = (1<<8) - 1, ans = inf;
	for(int mask1=0; mask1<=all; ++mask1)
		for(int mask2=0; mask2<=all; ++mask2)
			if(check(mask1, mask2))
				ans = min(ans, get_num1(mask1) + get_num1(mask2));
	printf("%d",ans);
	return 0;
}