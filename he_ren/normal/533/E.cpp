#include<cstdio>
const int MAXN = 1e5 + 5;

char s[MAXN],t[MAXN];

int main(void)
{
	int n;
	scanf("%d%s%s",&n,s+1,t+1);
	
	int l,r;
	for(l=1; s[l]==t[l]; ++l);
	for(r=n; s[r]==t[r]; --r);
	
	int ans=0,i;
	for(i=l; i<r && s[i] == t[i+1]; ++i);
	if(i==r) ++ans;
	for(i=l; i<r && s[i+1] == t[i]; ++i);
	if(i==r) ++ans;
	
	printf("%d",ans);
	return 0;
}