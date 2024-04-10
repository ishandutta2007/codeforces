#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

int n;
char s[MAXN];
int a[MAXN];

int t[30];
bool can[30];
bool chk(int mid)
{
	for(int i=0; i<26; ++i) t[i]=0;
	for(int i=1; i<=mid; ++i) ++t[a[i]];
	for(int i=0; i<26; ++i) can[i]=t[i];
	
	for(int i=2; i+mid-1<=n; ++i)
	{
		--t[a[i-1]]; ++t[a[i+mid-1]];
		if(!t[a[i-1]]) can[a[i-1]]=0;
	}
	
	for(int i=0; i<26; ++i)
		if(can[i]) return 1;
	return 0;
}

int main(void)
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; ++i) a[i] = s[i]-'a';
	
	int l=1, r=n;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}