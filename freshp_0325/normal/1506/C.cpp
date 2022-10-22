#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
#define mp make_pair
int n,m;
char s[25],t[25];
void Solve()
{
	scanf("%s %s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	int ans=0;
	for(int l1=1;l1<=n;++l1)
	{
		for(int r1=l1;r1<=n;++r1)
		{
			for(int l2=1;l2<=m;++l2)
			{
				for(int r2=l2;r2<=m;++r2)
				{
					if(r1-l1+1!=r2-l2+1)	continue;
					for(int k=1;k<=r1-l1+1;++k)	
					if(s[l1+k-1]!=t[l2+k-1])
						goto fail;
//					printf("[%d, %d] [%d, %d]\n",l1,r1,l2,r2);
					ans=max(ans,(r2-l2+1)+(r1-l1+1));
					fail:;
				}
			}
		}
	}
	printf("%d\n",n+m-ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}