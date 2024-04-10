#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
const int inf=1e9;
const ll Inf=1e18;
const int u[]={0,1,2,0,2,1,0};
int a[3],b[3];
int main(){int ans=0;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	rep(i,0,6){
		rep(j,0,2)b[j]=a[j];
		int t=min(min(a[0]/3,a[1]/2),a[2]/2);
		b[0]-=t*3;b[1]-=t*2;b[2]-=t*2;
		t*=7;ans=max(ans,t);
		rep(j,i,i+6){
			if(!b[u[j%7]]--)break;
			ans=max(ans,++t);
		}
	}
	printf("%d\n",ans);
}