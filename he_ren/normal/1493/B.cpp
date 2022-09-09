#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

int to[] = {0,1,5,-1,-1,2,-1,-1,8,-1};
inline int rev(int x){ return to[x%10] < 0 || to[x/10] < 0? inf: to[x%10] * 10 + to[x/10];}

void solve(void)
{
	int h,m,x,y;
	scanf("%d%d%d:%d",&h,&m,&x,&y);
	while(1)
	{
		int tx = rev(y), ty = rev(x);
		if(tx < h && ty < m)
		{
			printf("%02d:%02d\n",x,y);
			return;
		}
		++y;
		if(y == m) y = 0, ++x;
		if(x == h) x = 0;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}