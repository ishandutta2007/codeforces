#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define clean(a) memset(a,0,sizeof(a))
const int MAXN = 9 + 5;
const int t[4][4]={
{1,2,3},
{4,5,6},
{7,8,9}};

int in(int x,int y){ return t[(x-1)/3][(y-1)/3];}

char s[MAXN][MAXN];
int a[MAXN][MAXN];
bool r[10],c[10],b[10];

int rt[10][10], ct[10][10], bt[10][10];
int rc[10], cc[10], bc[10];

void solve(void)
{
	int n=9;
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j] = s[i][j]-'0';
	
	clean(r);
	clean(c);
	clean(b);
	memset(rt,0,sizeof(rt));
	memset(bt,0,sizeof(bt));
	memset(ct,0,sizeof(ct));
	clean(rc);
	clean(cc);
	clean(bc);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			++rt[i][a[i][j]];
			++ct[j][a[i][j]];
			++bt[in(i,j)][a[i][j]];
		}
	
	for(int i=1; i<=9; ++i)
	{
		for(int j=1; j<=9; ++j)
		{
			if(rt[i][j]>1) ++rc[i];
			if(ct[i][j]>1) ++cc[i];
			if(bt[i][j]>1) ++bc[i];
		}
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			int k=in(i,j);
			if(r[i] || c[j] || b[k]) continue;
			r[i]=c[j]=b[k]=1;
			int y=a[i][j];
			
			for(int x=1; x<=9; ++x)
			{
				if(--rt[i][y] == 1) --rc[i];
				if(--ct[j][y] == 1) --cc[j];
				if(--bt[k][y] == 1) --bc[k];
				if(++rt[i][x] == 2) ++rc[i];
				if(++ct[j][x] == 2) ++cc[j];
				if(++bt[k][x] == 2) ++bc[k];
				
				if(rc[i]>1 && cc[j]>1 && bc[k]>1)
				{
					a[i][j]=x;
					break;
				}
			}
		}
	for(int i=1; i<=n; ++i,putchar('\n'))
		for(int j=1; j<=n; ++j) putchar(a[i][j]+'0');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}