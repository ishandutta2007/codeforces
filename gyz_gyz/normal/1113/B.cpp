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
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];
int main(){int n,tot=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
	}
	sort(a+1,a+n+1);int ans=0;
	rep(i,2,n)rep(j,2,a[i])
		if(!(a[i]%j))ans=max(ans,a[i]-a[i]/j-a[1]*(j-1));
	printf("%d\n",tot-ans);
}