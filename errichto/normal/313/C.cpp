#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

int n,pom;
ll t[2000005],lvl,RES;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%I64d",&t[i]);
	sort(t,t+n);
	reverse(t,t+n);
	pom=1;
	int npom=n;
	while(npom){
		lvl++;
		npom/=4;
	}
	RES=lvl*t[0];
	lvl--;
	while(pom<n){
		for(int i=pom+1;i<=4*pom;++i)
			RES+=lvl*t[i-1];
		pom=4*pom;
		lvl--;
	}
	printf("%I64d",RES);
	return 0;
}