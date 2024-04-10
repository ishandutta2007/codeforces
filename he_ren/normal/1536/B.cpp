#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i='a'; i<='z'; ++i)
	{
		bool ok = 0;
		for(int j=1; j<=n; ++j)
			if(s[j] == i)
			{
				ok = 1;
				break;
			}
		if(!ok){ printf("%c\n",(char)i); return;}
	}
	
	for(int i='a'; i<='z'; ++i)
		for(int j='a'; j<='z'; ++j)
		{
			bool ok = 0;
			for(int x=1; x<n; ++x)
				if(s[x] == i && s[x+1] == j)
				{
					ok = 1;
					break;
				}
			if(!ok){ printf("%c%c\n",(char)i,(char)j); return;}
		}
	
	for(int i='a'; i<='z'; ++i)
		for(int j='a'; j<='z'; ++j)
			for(int k='a'; k<='z'; ++k)
			{
				bool ok = 0;
				for(int x=1; x+2<=n; ++x)
					if(s[x] == i && s[x+1] == j && s[x+2] == k)
					{
						ok = 1;
						break;
					}
				if(!ok){ printf("%c%c%c\n",(char)i,(char)j,(char)k); return;}
			}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}