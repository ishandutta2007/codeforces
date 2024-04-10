#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 4 + 5;
const int ALL = (1<<8) + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define bbit2(i) (1<<((i)<<1))
#define bdig2(x,i) (((x)>>((i)<<1))&3)

int a[MAXM];
char s[MAXN][MAXM];
int f[MAXN][MAXM][ALL], to[ALL][MAXM][MAXM];
bool fob[ALL];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=4; ++i) scanf("%d",&a[i]);
	for(int j=1; j<=4; ++j)
	{
		static char ss[MAXN];
		scanf("%s",ss+1);
		for(int i=1; i<=n; ++i) s[i][j] = ss[i];
	}
	
	int all = (1<<8) - 1;
	
	for(int mask=0; mask<=all; ++mask)
	{
		for(int i=0; i<4; ++i)
			if(bdig2(mask, i) == 3) fob[mask] = 1;
		for(int i=1; i<=4; ++i)
			for(int j=0; j<=i; ++j)
			{
				int &cur = to[mask][i][j] = mask;
				for(int k=i-j+1; k<=i; ++k)
					if(bdig2(cur, k-1) <= j)
						cur &= ~(3 << ((k-1)<<1));
			}
	}
	
	memset(f,0x3f,sizeof(f));
	f[0][4][0] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int mask=0; mask<=all; ++mask) if(f[i-1][4][mask] < inf)
		{
			f[i][0][mask] = f[i-1][4][mask];
			if(fob[mask])
				chk_min(f[i][4][0], f[i][0][mask] + a[4]),
				f[i][0][mask] = inf;
		}
		for(int j=1; j<=4; ++j)
			for(int mask=0; mask<=all; ++mask) if(f[i][j-1][mask] < inf)
			{
				int nmask = mask;
				if(bdig2(mask, j-1) || s[i][j] == '*')
					nmask += bbit2(j-1);
				
				for(int k=0; k<=j && k<=i; ++k)
					chk_min(f[i][j][ to[nmask][j][k] ], f[i][j-1][mask] + a[k]);
			}
	}
	
	printf("%d",f[n][4][0]);
	return 0;
}