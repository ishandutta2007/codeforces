#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXD = 17 + 5;
const int ALL = (1<<17) + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n,d,all;
char s[MAXN];

int pos[MAXD][MAXN];
int f[ALL];

inline bool chk(int x)
{
	if(d * x > n) return 0;
	for(int i=0; i<d; ++i)
	{
		pos[i][n+1] = n+1;
		for(int j=n, len=0; j>=1; --j)
		{
			if(s[j] != '?' && s[j] != i + 'a') len = 0;
			else ++len;
			pos[i][j] = len >= x? j+x-1: pos[i][j+1];
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for(int mask=0; mask<all; ++mask) if(f[mask] <= n)
	{
		int cur = f[mask];
		for(int i=0; i<d; ++i) if(!bdig(mask, i))
		{
			int nxt = pos[i][cur+1];
			if(nxt <= n)
				chk_min(f[mask | bbit(i)], nxt);
		}
	}
	
	return f[all] <= n;
}

int main(void)
{
	scanf("%d%d%s",&n,&d,s+1);
	all = (1<<d) - 1;
	
	int l = 0, r = n;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}