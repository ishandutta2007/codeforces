#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;

int n;
char s[MAXN];
int tx,ty;
int sumx[MAXN],sumy[MAXN];

bool chk(int mid)
{
	for(int i=1; i+mid-1<=n; ++i)
	{
		int j=i+mid-1;
		int x = sumx[n]-sumx[j]+sumx[i-1];
		int y = sumy[n]-sumy[j]+sumy[i-1];
		int dis = abs(tx-x)+abs(ty-y);
		int stp = j-i+1;
		if(dis<=stp && (dis&1)==(stp&1))
			return 1;
	}
	return 0;
}

int main(void)
{
	scanf("%d%s%d%d",&n,s+1,&tx,&ty);
	for(int i=1; i<=n; ++i)
	{
		sumx[i]=sumx[i-1];
		sumy[i]=sumy[i-1];
		if(s[i]=='U') ++sumy[i];
		if(s[i]=='D') --sumy[i];
		if(s[i]=='L') --sumx[i];
		if(s[i]=='R') ++sumx[i];
	}
	
	int l=0, r=n+1;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	if(l>n) printf("-1");
	else printf("%d",l);
	return 0;
}