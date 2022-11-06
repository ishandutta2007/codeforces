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
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];
int main(){int n;
	scanf("%d",&n);
	int nw=0,ans=0;
	rep(i,0,n*2-2){
		if(i<n)scanf("%d",&a[i]);
		if(a[i%n])ans=max(ans,++nw);
		else nw=0;
	}
	printf("%d\n",ans);
}