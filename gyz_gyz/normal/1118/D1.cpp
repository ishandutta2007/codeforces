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
#define N 100010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];
int main(){int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n+1,m=(l+r)/2;
	for(;l<r;m=(l+r)/2){ll tot=0;int dm=0;
		dep(i,n,1){
			if(a[i]<=dm)break;
			tot+=a[i]-dm;
			if((n-i)%m==m-1)++dm;
		}
		if(tot<k)l=m+1;else r=m;
	}
	printf("%d\n",m>n?-1:m);
}