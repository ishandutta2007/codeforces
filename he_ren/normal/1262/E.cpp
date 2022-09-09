#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;

inline int squ(int x){ return x*x;}

int n,m;
char str[MAXM];
vector<int> a[MAXN],s[MAXN],t[MAXN];

bool chk(int mid,bool flag)
{
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			t[i][j]=0;
	
	int area = squ((mid<<1)+1);
	for(int i=mid+1; i+mid<=n; ++i)
		for(int j=mid+1; j+mid<=m; ++j)
		{
			int il=i-mid-1, ir=i+mid;
			int jl=j-mid-1, jr=j+mid;
			if(s[ir][jr]-s[ir][jl]-s[il][jr]+s[il][jl] == area)
				t[i][j]=1;
		}
	
	if(flag) return 1;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int il=max(i-mid-1,0), ir=min(i+mid,n);
			int jl=max(j-mid-1,0), jr=min(j+mid,m);
			int sum=t[ir][jr]-t[ir][jl]-t[il][jr]+t[il][jl];
			if(a[i][j] && !sum) return 0;
			if(!a[i][j] && sum) return 0;
		}
	return 1;
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=0; i<=n+1; ++i)
		a[i].resize(m+2), s[i].resize(m+2), t[i].resize(m+2);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",str+1);
		for(int j=0; j<=m+1; ++j)
			a[i][j] = (str[j]=='X');
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			s[i][j] = a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	
	int l=0, r=min(n,m)>>1;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid,0)) l=mid;
		else r=mid-1;
	}
	
	chk(l,1);
	printf("%d\n",l);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
			putchar(t[i][j]? 'X': '.');
		putchar('\n');
	}
	return 0;
}