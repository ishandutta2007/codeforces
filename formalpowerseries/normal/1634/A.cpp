#include<bits/stdc++.h>
using namespace std;
char s[105];
void Solve()
{
	int n,k;
	scanf("%d %d %s",&n,&k,s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]!=s[n-i+1])	goto ok;
	}
	puts("1");
	return ;
	ok:;
	if(k==0)	puts("1");
	else	puts("2");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}