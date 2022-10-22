#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,p[2][N];
char s[N];
int main()
{
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<2;j++)
			p[j][i]=p[j][i-1];
		if(s[i]==s[i-1])
			p[s[i]-'0'][i]++;
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",max(p[0][r]-p[0][l],p[1][r]-p[1][l])+1);
	}
	return 0;
}