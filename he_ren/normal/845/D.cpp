#include<cstdio>
#include<stack>
using namespace std;
const int inf = 0x3f3f3f3f;

stack<int> s;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int spd, cnt=0;
	s.push(inf);
	
	int ans=0;
	while(n--)
	{
		int q;
		scanf("%d",&q);
		if(q==1)
		{
			scanf("%d",&spd);
			while(s.top()<spd) s.pop(), ++ans;
		}
		if(q==2)
		{
			ans+=cnt;
			cnt=0;
		}
		if(q==3)
		{
			int x;
			scanf("%d",&x);
			if(x<spd) ++ans;
			else s.push(x);
		}
		if(q==4) cnt=0;
		if(q==5)
		{
			while(s.top()!=inf) s.pop();
		}
		if(q==6) ++cnt;
	}
	printf("%d",ans);
	return 0;
}