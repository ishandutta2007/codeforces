#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double> 
LL front[300005],back[300005];
LL pre[300005];
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	int a[300005];
	for(int i = 1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i<=n;i++){
		front[i]=max(front[i-1]+a[i],0ll);
		pre[i]=pre[i-1]+a[i];
	}
	for(int i = n;i>=1;i--){
		back[i]=max(back[i+1]+a[i],0ll);
	}
	LL Max=0;
	LL ans=0;
	for(int i = 1;i<=n;i++){
		Max=max(Max,front[i]-x*pre[i]);
		ans=max(pre[i]*x+back[i+1]+Max,ans);
	}
	printf("%lld\n",ans);

}