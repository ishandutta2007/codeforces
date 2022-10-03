#include<bits/stdc++.h>
using namespace std;

int h1[1000010],h2[1000010],n,t1,t2;
char s[1000010];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while (r-l>2)
	{
		if (s[l]==s[r]) h1[++t1]=l,h2[++t2]=r,l++,r--;
		else if (s[l]==s[r-1]) h1[++t1]=l,h2[++t2]=r-1,l++,r-=2;
		else if (s[l+1]==s[r]) h1[++t1]=l+1,h2[++t2]=r,l+=2,r--;
		else h1[++t1]=l+1,h2[++t2]=r-1,l+=2,r-=2;
	}
	if (l<=r) h1[++t1]=l;
	for (int i=1;i<=t1;i++) putchar(s[h1[i]]);
	for (int i=t2;i;i--) putchar(s[h2[i]]);
	putchar('\n');
	return 0;
}