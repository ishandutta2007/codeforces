#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
int m,a[N],v[N];ll r[N];
int qk(int x,ll y){int r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%m;x=x*x%m;
	}return r;
}
int main(){int n;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n){
		int x=a[i]%m;
		rep(j,0,m-1){
			r[x]+=v[j];
			if(x==m-1)x=0;else ++x;
		}
		++v[(m-x)%m];
	}int ans=1;
	rep(i,0,m-1)ans=ans*qk(i,r[i])%m;
	printf("%d\n",ans);
}