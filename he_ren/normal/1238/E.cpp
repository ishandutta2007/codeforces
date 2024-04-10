#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 20 + 5;
const int ALL = (1<<20) + 5;
const int inf = 0x3f3f3f3f;

#define bit(i) (1ll<<(i))
#define lowbit(x) ((x)&-(x))

inline int Abs(int x){ return x<0? -x: x;}

char s[MAXN];
int f[ALL];

int g[MAXM][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	
	for(int i=1; i<n; ++i)
		++g[s[i]-'a'][s[i+1]-'a'],
		++g[s[i+1]-'a'][s[i]-'a'];
	
	int all = (1<<m) - 1;
	f[0] = 0;
	for(int mask = 1; mask <= all; ++mask)
	{
		f[mask] = inf;
		for(int i=0; i<m; ++i) if(mask & bit(i))
			f[mask] = min(f[mask], f[mask ^ bit(i)]);
		
		for(int i=0; i<m; ++i) if(mask & bit(i))
			for(int j=0; j<m; ++j) if(~mask & bit(j))
				f[mask] += g[i][j];
	}
	printf("%d",f[all]);
	return 0;
}