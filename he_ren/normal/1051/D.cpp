#include<cstdio>
#include<cstring>
typedef long long ll;
const int MAXN = 1e3 + 5;
const int mod = 998244353;
const int tot[4]={1,2,2,1};
const int more[4][4]={
{0,0,0,1},
{1,0,2,1},
{1,2,0,1},
{1,0,0,0}};

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int f[MAXN][MAXN*2][5];
int gao(int x,int y,int s)
{
	if(y<=0 || y>(x<<1)) return 0;
	if(~f[x][y][s]) return f[x][y][s];
	if(x==1) return f[x][y][s] = (tot[s]==y);
	
	int &res=f[x][y][s]=0;
	for(int t=0; t<4; ++t)
		add_mod(res, gao(x-1,y-more[s][t],t));
	return res;
}

int main(void)
{
	memset(f,-1,sizeof(f));
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	int ans=0;
	for(int s=0; s<4; ++s)
		add_mod(ans, gao(n,m,s));
	printf("%d",ans);
	return 0;
}