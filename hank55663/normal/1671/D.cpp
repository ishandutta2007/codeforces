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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
	int n,x;
	scanf("%d %d",&n,&x);
	int a[200005];
	LL ans=0;
	int Max=0,Min=1e9;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		if(i!=0)ans+=abs(a[i]-a[i-1]);
		Max=max(Max,a[i]);
		Min=min(Min,a[i]);
	}
	if(x>Max){
		ans+=min((x-Max)*2,x-max(a[0],a[n-1]));
	}
	if(Min>1){
		ans+=min((Min-1)*2,min(a[0],a[n-1])-1);
	}
	printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/