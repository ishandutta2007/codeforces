#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 2e5 + 5;

char s[MAXN];
int t[10 + 5];

void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i) s[i]-='0';
	
	if(s[1]==1)
	{
		bool flag=1;
		for(int i=2; i<n; ++i)
			if(s[i]){ flag=0; break;}
		if(flag && s[n]<=1)
		{
			for(int i=3; i<=n; ++i) putchar('9');
			putchar('\n');
			return;
		}
	}
	
	memset(t,0,sizeof(t));
	for(int i=1; i<=n; ++i) ++t[(int)s[i]];
	
	for(int i=n; i>=1; --i)
	{
		--t[(int)s[i]];
		for(int j=s[i]-1; j>=0; --j)
		{
			++t[j];
			
			int cnt=0;
			for(int k=0; k<=9; ++k)
				if(t[k]&1) ++cnt;
			if(n-i>=cnt && !((n-i-cnt)&1))
			{
				s[i]=j;
				for(int k=1; k<=i; ++k) putchar(s[k]+'0');
				for(int k=cnt; k<n-i; ++k) putchar('9');
				for(int k=9; k>=0; --k)
					if(t[k]&1) putchar(k+'0');
				putchar('\n');
				return;
			}
			
			--t[j];
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}