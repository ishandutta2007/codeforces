#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool cmp(pii x,pii y){return x>y;}
int a[N];pii s[N];
int main(){int n,m,k;ll tot=0;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);
		s[i]={a[i],i};
	}
	sort(s+1,s+n+1,cmp);
	rep(i,1,m*k)tot+=s[i].fr;
	printf("%lld\n",tot);tot=0;
	rep(i,1,n)if(pii(a[i],i)>=s[m*k]){
		if(++tot>m)printf("%d ",i-1),tot=1;
	}
}