#include<cstdio>
const int MAXN = 1e3 + 5;
const int MAXK = 1e3 + 5;

char s[MAXN];
int dp_[MAXN][MAXK*2];
char lst_[MAXN][MAXK*2];
#define dp(i,j) dp_[i][(j)+MAXK]
#define lst(i,j) lst_[i][(j)+MAXK]

char ans[MAXN];

int main(void)
{
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	
	dp(1,0)=1;
	for(int i=1; i<=n; ++i)
		for(int j=-k+1; j<k; ++j)
			if(dp(i,j))
			{
				if(s[i]=='W') dp(i+1, j+1)=1, lst(i+1, j+1)='W';
				if(s[i]=='L') dp(i+1, j-1)=1, lst(i+1, j-1)='L';
				if(s[i]=='D') dp(i+1, j)=1, lst(i+1, j)='D';
				if(s[i]=='?')
				{
					dp(i+1,j-1)=dp(i+1,j)=dp(i+1,j+1)=1,
					lst(i+1, j+1)='W';
					lst(i+1, j-1)='L';
					lst(i+1, j)='D';
				}
			}
	
	if(dp(n+1,k) || dp(n+1,-k))
	{
		int j = dp(n+1,k)? k: -k;
		for(int i=n+1; i>1; --i)
		{
			char c=lst(i,j);
			ans[i-1]=c;
			if(c=='W') --j;
			if(c=='L') ++j;
		}
		printf("%s",ans+1);
		return 0;
	}
	printf("NO");
	return 0;
}