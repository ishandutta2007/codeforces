#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int mo=998244353;
int a[N];
void sol(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	k=min(k,m-1);int ls=m-k-1;m=n-m+1;
	rep(i,1,n)scanf("%d",&a[i]);
	int ans=0;
	rep(i,1,k+1){
		int r=1e9+10;
		rep(j,i,i+ls)r=min(r,max(a[j],a[j+m-1]));
		ans=max(ans,r);
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}