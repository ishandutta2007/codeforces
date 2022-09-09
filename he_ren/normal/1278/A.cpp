#include<cstdio>
#include<cstring>
const int MAXN = 1e2 + 5;

char p[MAXN],h[MAXN];
int tp[30],th[30];

void solve(void)
{
	scanf("%s%s",p+1,h+1);
	int n=strlen(p+1), m=strlen(h+1);
	if(m<n){ printf("NO\n"); return;}
	
	memset(tp,0,sizeof(tp));
	memset(th,0,sizeof(th));
	for(int i=1; i<=n; ++i)
		++tp[p[i]-'a'], ++th[h[i]-'a'];
	
	for(int i=1,j=n; j<=m;)
	{
		bool flag=1;
		for(int k=0; k<26; ++k)
			if(tp[k]!=th[k])
			{
				flag=0;
				break;
			}
		if(flag){ printf("YES\n"); return;}
		
		--th[h[i]-'a']; ++i;
		if(++j>m) break;
		++th[h[j]-'a'];
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}