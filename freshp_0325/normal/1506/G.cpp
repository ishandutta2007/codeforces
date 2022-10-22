#include<bits/stdc++.h>
using namespace std;
char s[200005],ans[200005];
int n,p[250];
bool used[250];
void Solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(p,0,sizeof p);
	memset(used,false,sizeof used);
	for(int i=1;i<=n;++i)	p[s[i]]=i;
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(used[s[i]])	continue;
		while(cnt && ans[cnt]<s[i] && p[ans[cnt]]>i)	used[ans[cnt]]=false,--cnt;
		ans[++cnt]=s[i];
		used[s[i]]=true;
	}
	ans[cnt+1]=0;
	puts(ans+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}