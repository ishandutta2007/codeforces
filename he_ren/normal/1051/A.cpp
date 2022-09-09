#include<cstdio>
#include<cstring>
const int MAXN = 1e2 + 5;

char s[MAXN];
int a[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	int flag=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]>='a' && s[i]<='z') flag|=(a[i]=1);
		if(s[i]>='A' && s[i]<='Z') flag|=(a[i]=2);
		if(s[i]>='0' && s[i]<='9') flag|=(a[i]=4);
	}
	if(flag==1) s[1]='A', s[2]='0', flag=7;
	if(flag==2) s[1]='a', s[2]='0', flag=7;
	if(flag==4) s[1]='A', s[2]='a', flag=7;
	if(flag==7){ printf("%s\n",s+1); return;}
	
	for(int i=2; i<n; ++i)
		if(a[i]!=a[i-1])
		{
			if(!(flag&1)) s[i+1]='a';
			if(!(flag&2)) s[i+1]='A';
			if(!(flag&4)) s[i+1]='0';
			printf("%s\n",s+1);
			return;
		}
	for(int i=2; i<n; ++i)
		if(a[i]!=a[i+1])
		{
			if(!(flag&1)) s[i-1]='a';
			if(!(flag&2)) s[i-1]='A';
			if(!(flag&4)) s[i-1]='0';
			printf("%s\n",s+1);
			return;
		}
}


int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}