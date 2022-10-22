#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,p[30],b;
char s[N];
void sol()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=0;i<26;i++)
		p[i]=0;
	for(int i=1;i<=n;i++)
		p[s[i]-'a']=i;
	b=n+1;
	for(int i=0;i<26;i++)
		if(p[i])
			b=min(b,p[i]);
	for(int i=b;i<=n;i++)
		printf("%c",s[i]);
	puts("");	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}