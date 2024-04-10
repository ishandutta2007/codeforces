#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXM = 3e5 + 5;
using namespace std;

struct Mouse
{
	int c,t;
}p[MAXM];
inline bool cmp(Mouse &x,Mouse &y){ return x.c<y.c;}

char s[10];

int main(void)
{
	int a,b,c,m;
	scanf("%d%d%d%d",&a,&b,&c,&m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%s",&p[i].c,s);
		p[i].t = (s[0]=='U');
	}
	
	sort(p+1,p+m+1,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1; i<=m; ++i)
	{
		int* x;
		if(p[i].t)
		{
			if(a) x=&a;
			else x=&c;
		}
		else
		{
			if(b) x=&b;
			else x=&c;
		}
		
		if(*x)
		{
			--(*x); ++cnt;
			ans+=p[i].c;
		}
	}
	
	cout<<cnt<<" "<<ans;
	return 0;
}