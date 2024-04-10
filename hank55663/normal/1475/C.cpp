#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
pii p[200005];
bool solve(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int cnt[200005],cnt2[200005];
	fill(cnt,cnt+n+1,0);
	fill(cnt2,cnt2+m+1,0);
	for(int i = 0;i<k;i++)scanf("%d",&p[i].x),cnt[p[i].x]++;
	for(int i = 0;i<k;i++)scanf("%d",&p[i].y),cnt2[p[i].y]++;
	LL ans=0;
	for(int i = 0;i<k;i++){
		ans+=k-cnt[p[i].x]-cnt2[p[i].y]+1;
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans/2);
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/