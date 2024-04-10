#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e2 + 5;
const int inf = 0x3f3f3f3f;

char s[MAXN];
int go[MAXN];

int f[MAXN][MAXN];
int gao(int l,int r)
{
	if(l>r) return 0;
	if(~f[l][r]) return f[l][r];
	int &res = f[l][r] = inf;
	
	res = gao(l+1,r) + 1;
	for(int i=l+1; i<=r; ++i)
	{
		if(s[i] == s[l])
			res = min(res, gao(l+1,i-1) + gao(i,r));
	}
	return res;
}

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	memset(f,-1,sizeof(f));
	printf("%d",gao(1,n));
	return 0;
}