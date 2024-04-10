#include<cstdio>
const int MAXN = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN],t[MAXN];
int ltr[MAXN][30],tot[30];
int cnt[30];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i)
		ltr[ ++tot[s[i]-'a'] ][s[i]-'a'] = i;
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		for(int i=0; i<26; ++i) cnt[i]=0;
		
		scanf("%s",t);
		int ans=0;
		for(int i=0; t[i]; ++i)
			chk_max(ans, ltr[ ++cnt[t[i]-'a'] ][t[i]-'a']);
		printf("%d\n",ans);
	}
	return 0;
}