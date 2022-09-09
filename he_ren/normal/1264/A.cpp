#include<cstdio>
#include<cstdlib>
const int MAXN = 4e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mid=n>>1;
	while(mid>=3 && a[mid]==a[mid+1]) --mid;
	if(mid<3){ printf("0 0 0\n"); return;}
	
	int g=1;
	for(; a[g+1]==a[g]; ++g);
	
	int s=g+1;
	for(; s<=mid && (a[s+1]==a[s] || s-g<=g); ++s);
	if(s>mid){ printf("0 0 0\n"); return;}
	if(mid-s <= g){ printf("0 0 0\n"); return;}
	
	printf("%d %d %d\n",g,s-g,mid-s);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}