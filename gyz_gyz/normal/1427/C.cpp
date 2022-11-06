#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=998244353;
const ll inf=1e18;
int t[N],x[N],y[N],a[N];
int main(){int n,m;
	scanf("%d%d",&m,&n);
	x[0]=y[0]=1;int k=0,mx=-n,ans=0;
	rep(i,1,n){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		while(t[i]-t[k]>m*2)mx=max(mx,a[k++]);
		a[i]=mx+1;
		rep(j,k,i-1)if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
			a[i]=max(a[i],a[j]+1);
		ans=max(ans,a[i]);
	}
	printf("%d\n",ans);
}