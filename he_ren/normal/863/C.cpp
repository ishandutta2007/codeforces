#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXA = 3 + 5;

inline bool win(int x,int y)
{
	--x;
	if(!x) x=3;
	return x==y;
}

int a[MAXA][MAXA],b[MAXA][MAXA],s[MAXA][MAXA],p[MAXA*MAXA][2];

int main(void)
{
	ll n;
	int x,y;
	cin>>n>>x>>y;
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=3; ++j) scanf("%d",&a[i][j]);
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=3; ++j) scanf("%d",&b[i][j]);
	
	s[x][y]=1;
	p[1][0]=win(x,y);
	p[1][1]=win(y,x);
	int m=1;
	while(m<n)
	{
		++m;
		int lx=x, ly=y;
		x=a[lx][ly]; y=b[lx][ly];
		p[m][0]=p[m-1][0]+win(x,y);
		p[m][1]=p[m-1][1]+win(y,x);
		if(s[x][y]) break;
		s[x][y]=m;
	}
	if(m==n)
	{
		printf("%d %d",p[m][0],p[m][1]);
		return 0;
	}
	int beg = s[x][y];
	n -= beg;
	for(int i=0; i<=1; ++i)
	{
		ll ans = p[beg][i];
		int l = m-beg;
		ans += n/l * (p[m][i]-p[beg][i]) + p[beg+n%l][i]-p[beg][i];
		cout<<ans<<' ';
	}
	return 0;
}