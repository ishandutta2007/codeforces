#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;
const int MAXN = 1e6 + 5;
ll linf = 0x3f3f3f3f3f3f3f3f;
const ldb eps = 1e-7;

inline ldb Fabs(ldb x){ return x<0? -x: x;}
inline bool eq(ldb x,ldb y){ return Fabs(x-y)<=eps;}

inline ldb calc(int a,int b){ return (ldb)4*(a+b)*(a+b)/(a*b);}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	ldb ans=linf;
	int lst=-1, A=-1, B=-1;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[j]==a[i]) ++j;
		if(j-i<2) continue;
		
		if(j-i>=4) lst=a[i];
		if((~lst) && calc(lst,a[i]) < ans)
		{
			ans=calc(lst,a[i]);
			A=lst; B=a[i];
		}
		lst=a[i];
	}
	printf("%d %d %d %d\n",A,A,B,B);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}