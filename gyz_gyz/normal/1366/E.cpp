#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int a[N],b[N],l[N],r[N];
int main(){int n,m;ll ans=1;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	rep(i,1,n){
		int x=upper_bound(b+1,b+m+1,a[i])-b;
		if(x==1){
			printf("0\n");return 0;
		}
		if(b[x-1]==a[i])l[x-1]=i;
		r[x-1]=i;
	}
	if(!l[1]){
		printf("0\n");return 0;
	}
	rep(i,1,m-1){
		if(r[i]>l[i+1]){
			printf("0\n");return 0;
		}
		ans=ans*(l[i+1]-r[i])%mo;
	}
	printf("%lld\n",ans);
}