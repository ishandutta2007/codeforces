#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int ans=0;
	int all = (1<<8)-1;
	for(int i=1; i<=all; ++i)
	{
		int x=0,y=0,z=0;
		int tmp=0;
		for(int j=1; j<8; ++j)
			if((i>>j)&1)
			{
				++tmp;
				if(j&1) ++x;
				if(j&2) ++y;
				if(j&4) ++z;
			}
		if(x<=a && y<=b && z<=c && ans<tmp)
			ans=tmp;
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