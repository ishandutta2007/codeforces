#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int w[MAXN],t[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	n<<=1;
	for(int i=1; i<=n; ++i) scanf("%d",&w[i]);
	
	sort(w+1,w+n+1);
	int ans=inf;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
		{
			int cnt=0;
			for(int k=1; k<=n; ++k)
				if(k!=i && k!=j) t[++cnt]=w[k];
			int res=0;
			for(int k=1; k<=cnt; k+=2)
				res += t[k+1]-t[k];
			chk_min(ans,res);
		}
	printf("%d",ans);
	return 0;
}