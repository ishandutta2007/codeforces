#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int n,d;
char s[MAXN];

int nxt[MAXN], t[30];
inline bool chk(char c)
{
	static int need[30];
	int pos = 0, rem = n;
	for(int i=0; i<26; ++i)
	{
		pos += t[i];
		need[i] = t[i]%d? d - t[i]%d: 0;
		rem -= t[i] + need[i];
	}
	if(rem < 0) return 0;
	if(s[pos] != c) return s[pos] < c;
	need[25] += rem;
	
	++pos;
	for(int i=25; i>=0; --i) if(need[i])
	{
		if(s[pos] != i + 'a')
			return i + 'a' > s[pos];
		if(nxt[pos] - pos == need[i])
		{
			pos = nxt[pos];
			continue;
		}
		if(nxt[pos] - pos < need[i])
			return i + 'a' > s[nxt[pos]];
		else return 0;
	}
	return 1;
}

void solve(void)
{
	scanf("%d%d",&n,&d);
	memset(s,0,n+2);
	scanf("%s",s+1);
	if(n%d){ printf("-1\n"); return;}
	
	nxt[n] = n + 1;
	for(int i=n-1; i>=1; --i)
		nxt[i] = s[i] == s[i+1]? nxt[i+1]: i+1;
	memset(t,0,sizeof(t));
	
	string res;
	for(int i=1; i<=n; ++i)
		for(int k=max('a',s[i])-'a'; k<26; ++k)
		{
			++t[k];
			if(chk(k + 'a'))
			{
				if(k + 'a' == s[i]){ res += s[i]; break;}
				res += k + 'a';
				
				static int need[30];
				int rem = n;
				for(int j=0; j<26; ++j)
					need[j] = t[j]%d? d - t[j]%d: 0,
					rem -= t[j] + need[j];
				need[0] += rem;
				
				for(int j=0; j<26; ++j)
					res += string(need[j], j + 'a');
				cout << res << endl;
				return;
			}
			--t[k];
		}
	cout << res << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}