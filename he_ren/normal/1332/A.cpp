#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define x1 adafsfd
#define x2 akdfhgbfdh
#define y1 afsdfgasdgf
#define y2 audkgfasb

void solve(void)
{
	int a,b,c,d;
	int x,y,x1,y1,x2,y2;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
	
	if(a && a==b && x1==x2){ printf("NO\n"); return;}
	if(c && c==d && y1==y2){ printf("NO\n"); return;}
	x = x-a+b;
	y = y-c+d;
	if(x>=x1 && x<=x2 && y>=y1 && y<=y2) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}