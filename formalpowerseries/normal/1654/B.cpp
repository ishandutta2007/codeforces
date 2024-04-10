/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[200005];
int n;
int oc[129];
void Solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(oc,0,sizeof oc);
	for(int i=1;i<=n;++i)	++oc[s[i]];
	for(int i=1;i<=n;++i)
	{
		if(oc[s[i]]==1)
		{
			for(int j=i;j<=n;++j)	putchar(s[j]);
			puts("");
			return ;
		}
		--oc[s[i]];
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}