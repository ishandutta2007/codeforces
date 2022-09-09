#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int p,f,cs,cw,s,w;
	scanf("%d%d%d%d%d%d",&p,&f,&cs,&cw,&s,&w);
	if(s>w){ swap(s,w); swap(cs,cw);}
	
	int ans = 0;
	for(int i=0; i<=cs && i<=p/s; ++i)
	{
		int x = min((p - i*s)/w, cw);
		int res = i + x;
		
		int y = min(f/s, cs - i);
		res += y + min((f - (y * s))/w, cw-x);
		
		ans = max(ans, res);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}