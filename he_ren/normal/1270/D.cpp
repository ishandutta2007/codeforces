#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 5e2 + 5;

int n,d;

inline pii ask(int x)
{
	putchar('?');
	for(int i=1; i<=d+1; ++i)
		if(i!=x) printf(" %d",i);
	putchar('\n');
	fflush(stdout);
	pii res;
	scanf("%d%d",&res.fir,&res.sec);
	return res;
}

int main(void)
{
	scanf("%d%d",&n,&d);
	
	pii res = ask(d+1);
	int p=res.fir, x=res.sec;
	res = ask(p);
	int q=res.fir, y=res.sec;
	if(x>y) q=p;
	
	int ans=0;
	for(int i=1; i<=d; ++i)
	{
		if(i==p || i==q) continue;
		res = ask(i);
		if(res.fir == q) ++ans;
	}
	printf("! %d",ans+1);
	fflush(stdout);
	return 0;
}