#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	static int t[30];
	memset(t,0,sizeof(t));
	string f;
	for(int i=n; i>=1; --i)
	{
		if(!t[s[i] - 'a']) f += s[i];
		++t[s[i] - 'a'];
	}
	
	int tot = (int)f.size();
	for(int i=0; i<(int)f.size(); ++i)
	{
		if(t[f[i] - 'a'] % (tot - i))
		{
			printf("-1\n");
			return;
		}
		t[f[i] - 'a'] /= tot - i;
	}
	reverse(f.begin(), f.end());
	
	int rem = tot;
	for(int i=1; i<=n; ++i)
	{
		int c = s[i] - 'a';
		if(--t[c] < 0)
		{
			printf("-1\n");
			return;
		}
		if(t[c] == 0) --rem;
		
		if(rem) continue;
		
		string res, cur(s+1, s+i+1);
		for(int j=0; j<(int)f.size(); ++j)
		{
			res += cur;
			string nxt;
			for(int k=0; k<(int)cur.size(); ++k)
				if(cur[k] != f[j]) nxt += cur[k];
			cur = nxt;
		}
		
		if(res == string(s+1,s+n+1))
		{
			s[i+1] = 0;
			printf("%s ",s+1);
			cout << f << endl;
		}
		else printf("-1\n");
		return;
	}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}