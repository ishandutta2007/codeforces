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
#define index Index
using namespace std;
bool solve(){
	int n;
	scanf("%d",&n);
	LL c[100005];
	for(int i=0;i<n;i++)scanf("%lld",&c[i]);
	LL ans=1e18;
	LL sum=0;
	sum=c[0];
	LL Min1=c[0],Min2=c[1];
	for(int i = 1;i<n;i++){
		sum+=c[i];
		if(i&1)Min2=min(Min2,c[i]);
		else Min1=min(Min1,c[i]);
		ans=min(ans,sum+(n-(i+2)/2)*Min1+(n-(i+1)/2)*Min2);
	}
	printf("%lld\n",ans);
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}