#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

inline ll rnd(void){ return ((ll)rand()<<45) | ((ll)rand()<<30) | ((ll)rand()<<15) | rand();}

char s[MAXN];

const int base = 107, mod = 1e9 + 7;
int pwb[MAXN], h[MAXN][30];

inline int query_h(int c,int l,int r)
{
	int res = h[r][c] - (ll)h[l - 1][c] * pwb[r - l + 1] %mod;
	return res<0? res + mod: res;
}

int main(void)
{
	srand((unsigned long long)new char);
	
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	pwb[0] = 1;
	for(int i=1; i<MAXN; ++i) pwb[i] = (ll)pwb[i-1] * base %mod;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<26; ++j)
			h[i][j] = (ll)h[i-1][j] * base %mod;
		int c = s[i] - 'a';
		if(++h[i][c] >= mod) h[i][c] -= mod;
	}
	
	while(Q--)
	{
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		
		static int p1[30], p2[30];
		for(int i=0; i<26; ++i)
			p1[i] = query_h(i, x, x + len - 1),
			p2[i] = query_h(i, y, y + len - 1);
		sort(p1, p1+26);
		sort(p2, p2+26);
		
		bool ok = 1;
		for(int i=0; i<26; ++i)
			if(p1[i] != p2[i])
			{
				ok = 0;
				break;
			}
		
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}