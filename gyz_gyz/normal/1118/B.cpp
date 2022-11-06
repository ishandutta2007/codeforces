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
#define N 200010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];
int main(){int n,ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,3,n)a[i]+=a[i-2];
	rep(i,1,n){
		int l1,l2,r1,r2;
		if(n&1)r1=a[n],r2=a[n-1];
		else r1=a[n-1],r2=a[n];
		if(i&1)l1=i>1?a[i-2]:0,l2=a[i-1],r1-=a[i],r2-=l2;
		else l1=a[i-1],l2=a[i-2],r1-=l1,r2-=a[i];
		if(l1+r2==l2+r1)++ans;
	}printf("%d\n",ans);
}