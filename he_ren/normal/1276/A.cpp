#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1.5e5 + 5;

char s[MAXN];
bool del[MAXN];

bool One(int i){ return s[i]=='o' && s[i+1]=='n' && s[i+2]=='e';}
bool Two(int i){ return s[i]=='t' && s[i+1]=='w' && s[i+2]=='o';}


void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i) del[i]=0;
	
	int ans=0;
	for(int i=1; i+2<=n; ++i)
	{
		if(del[i]) continue;
		if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')
		{
			if(s[i+3]=='o') del[i+1]=1, ++ans;
			else del[i+2]=1, ++ans;
		}
		if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
			del[i+1]=1, ++ans;
	}
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i)
		if(del[i]) printf("%d ",i);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}