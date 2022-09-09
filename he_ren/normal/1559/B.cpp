#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int l=1,r=1; l<=n; l=r)
	{
		if(s[l] != '?'){ ++r; continue;}
		while(r <= n && s[r] == '?') ++r;
		char lef;
		if(l > 1) lef = s[l-1];
		else if(r <= n)
		{
			lef = s[r];
			if((r - l) % 2 == 0) lef = 'R' + 'B' - lef;
		}
		else lef = 'R'; 
		
		for(int i=l; i<r; ++i)
		{
			lef = 'R' + 'B' - lef;
			s[i] = lef;
		}
	}
	
	printf("%s\n",s+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}