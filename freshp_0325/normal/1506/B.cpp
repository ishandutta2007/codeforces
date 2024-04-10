#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
#define mp make_pair
int n,k;
char s[55];
int pos[55];
void Solve()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n;++i)	if(s[i]=='*')	pos[++cnt]=i;
	if(cnt==1)	puts("1");
	else if(cnt==2)	puts("2");
	else
	{
		int ans=1;
		for(int i=1;i<cnt;)
		{
			++ans;
			i=prev(upper_bound(pos+1,pos+1+cnt,pos[i]+k))-pos;
		}
		printf("%d\n",ans);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}