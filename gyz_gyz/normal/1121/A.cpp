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
#define N 250010
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,k,ans,a[N],t[N],s[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		scanf("%d",&t[i]);s[t[i]]=max(s[t[i]],a[i]);
	}
	rep(i,1,k){int x;
		scanf("%d",&x);
		if(s[t[x]]>a[x])++ans;
	}
	printf("%d\n",ans);
}