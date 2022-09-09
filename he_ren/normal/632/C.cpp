#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 5e4 + 5;
const int MAXL = 50 + 5;
using namespace std;

struct String
{
	char s[MAXL*2];
	int len;
}a[MAXN];
inline bool cmp(String &x,String &y)
{
	int lx=x.len, ly=y.len;
	for(int i=1; i<=ly; ++i) x.s[lx+i] = y.s[i];
	for(int i=1; i<=lx; ++i) y.s[ly+i] = x.s[i];
	for(int i=1; i<=lx+ly; ++i)
		if(x.s[i]!=y.s[i]) return x.s[i]<y.s[i];
	return 0;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%s",a[i].s+1),
		a[i].len=strlen(a[i].s+1);
	
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i)
		a[i].s[a[i].len+1]=0,
		printf("%s",a[i].s+1);
	return 0;
}