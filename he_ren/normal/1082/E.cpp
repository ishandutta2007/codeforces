#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned int uint;
const int MAXN = 5e5 + 5;
const int MAXA = 5e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];
int sum[MAXN];
vector<int> b[MAXA],mx[MAXA];

int main(void)
{
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int maxa=c;
	for(int i=1; i<=n; ++i)
		b[a[i]].push_back(i),
		chk_max(maxa,a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + (a[i]==c);
	
	int ans=sum[n];
	for(int i=1; i<=maxa; ++i)
	{
		for(uint j=0; j<b[i].size(); ++j)
			mx[i].push_back((j+1)-sum[b[i][j]]);
		for(int j=b[i].size()-2; j>=0; --j)
			chk_max(mx[i][j],mx[i][j+1]);
		
		for(uint j=0; j<b[i].size(); ++j)
			chk_max(ans, mx[i][j]-j+sum[b[i][j]-1] + sum[n]);
	}
	printf("%d",ans);
	return 0;
}