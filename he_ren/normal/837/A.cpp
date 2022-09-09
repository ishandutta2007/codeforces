#include<cstdio>
#include<cstring>
const int MAXN = 200 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	int ans=0;
	while(n>0)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		n -= l+1;
		
		int cnt=0;
		for(int i=1; i<=l; ++i)
			if(s[i]>='A' && s[i]<='Z') ++cnt;
		chk_max(ans,cnt);
	}
	
	printf("%d",ans);
	return 0;
}