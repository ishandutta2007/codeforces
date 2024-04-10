#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

char s[MAXN],t[MAXM];
int a[MAXN],b[MAXM];
bool has[26+3];
int suf[MAXN][26+3];

void solve(void)
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'a';
	for(int i=1; i<=m; ++i) b[i]=t[i]-'a';
	
	for(int i=0; i<26; ++i) has[i]=0;
	for(int i=1; i<=n; ++i) has[s[i]-'a']=1;
	for(int i=1; i<=m; ++i)
		if(!has[t[i]-'a']){ printf("-1\n"); return;}
	
	for(int i=0; i<26; ++i) suf[n+1][i]=-1;
	for(int i=n; i>=1; --i)
	{
		for(int j=0; j<26; ++j) suf[i][j]=suf[i+1][j];
		suf[i][s[i]-'a']=i;
	}
	
	int ans=0;
	for(int i=1,j=1; i<=m; i=j)
	{
		int k=1;
		while(j<=m && ~suf[k][t[j]-'a'])
			k=suf[k][t[j]-'a']+1, ++j;
		++ans;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}