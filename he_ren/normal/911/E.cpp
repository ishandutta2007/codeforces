#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
const int MAXN = 2e5 + 5;

inline void error(void){ printf("-1"); exit(0);}

int a[MAXN];
stack<int> s;

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	s.push(n+1);
	int now=1;
	for(int i=1; i<=d; ++i)
	{
		scanf("%d",&a[i]);
		
		while(now<=n && s.top()==now)
			s.pop(), ++now;
		if(a[i]>s.top()) error();
		s.push(a[i]);
	}
	while(now<=n && s.top()==now)
		s.pop(), ++now;
	
	for(int i=1; i<=d; ++i) printf("%d ",a[i]);
	while(now<=n)
	{
		for(int i=s.top()-1; i>=now; --i)
			printf("%d ",i);
		now=s.top()+1;
		s.pop();
	}
	return 0;
}