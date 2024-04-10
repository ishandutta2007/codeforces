#include<cstdio>
#include<cstring>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

inline void add(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

char s[MAXN];
int f[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	f[0]=f[1]=1;
	for(int i=2; i<=n; ++i)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=mod) f[i]-=mod;
	}
	
	int ans=1;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='m' || s[i]=='w')
		{
			printf("0");
			return 0;
		}
		if(s[i]!='n' && s[i]!='u') continue;
		
		int j=i;
		while(j<=n && s[j]==s[i]) ++j;
		ans = (ll)ans * f[j-i] %mod;
		i=j-1;
	}
	printf("%d",ans);
	return 0;
}