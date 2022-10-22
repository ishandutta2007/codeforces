#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
char s[55],t[55];
void Solve()
{
	scanf("%d %d",&n,&m);
	scanf("%s %s",s+1,t+1);
	for(int i=m;i;--i)
	{
		if(t[i]!=s[n-m+i])
		{
			if(i==1)
			{
				int c=t[i]-'0';
				for(int j=1;j<=n-m;++j)
				{
					if(s[j]-'0'==c)	return puts("YES"),void();
				}
				return puts("NO"),void();
			}
			else	return puts("NO"),void();
		}
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}