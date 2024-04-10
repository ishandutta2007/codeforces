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
bool solve(){
	int n;
	scanf("%d",&n);
	int cnt[3]={0,0,0};
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x%3]++;
	}
	int need=n/3;
	int sum=0;
	int ans=0;
	for(int i = 0;i<3;i++){
		if(cnt[i]>need){
			sum+=cnt[i]-need;
			cnt[i]=need;
		}
		if(cnt[i]<need){
			sum-=need-cnt[i];
			cnt[i]=need;
			if(sum<0)cnt[i]+=sum,sum=0;
		}
		ans+=sum;
	}
	for(int i = 0;i<3;i++){
		if(cnt[i]<need){
			sum-=need-cnt[i];
			cnt[i]=need;
			if(sum<0)cnt[i]+=sum,sum=0;
		}
		ans+=sum;
	}
	printf("%d\n",ans);//min(cnt[0]*2+cnt[1],min(cnt[1]*2+cnt[2],cnt[2]*2+cnt[0])));
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}