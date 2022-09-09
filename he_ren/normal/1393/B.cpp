#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXQ = 1e5 + 5;
const int MAXA = 1e5 + 5;

int t[MAXA];
int cnt[10];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		++t[a];
	}
	
	for(int i=1; i<MAXA; ++i)
		cnt[2] += t[i]/2,
		cnt[4] += t[i]/4;
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		static char s[10];
		int x;
		scanf("%s%d",s+1,&x);
		if(s[1] == '+')
		{
			if(t[x]%2 == 1) ++cnt[2];
			if(t[x]%4 == 3) ++cnt[4];
			++t[x];
		}
		else
		{
			if(t[x]%2 == 0) --cnt[2];
			if(t[x]%4 == 0) --cnt[4];
			--t[x];
		}
		if(!cnt[4]){ printf("NO\n"); continue;}
		if(cnt[2]-2 < 2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}