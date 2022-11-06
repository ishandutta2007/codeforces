#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=1e9+7;
int a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	int l=0,r=1e9+10;
	rep(i,2,n)if(~a[i]&&~a[i-1])l=max(l,abs(a[i]-a[i-1]));
	int m=(l+r)>>1;
	for(;l<r;m=(l+r)>>1){
		int lk=0,rk=1e9;
		rep(i,1,n)if(a[i]==-1){
			if(i>1&&~a[i-1]){
				lk=max(lk,a[i-1]-m);
				rk=min(rk,a[i-1]+m);
			}
			if(i<n&&~a[i+1]){
				lk=max(lk,a[i+1]-m);
				rk=min(rk,a[i+1]+m);
			}
		}
		if(lk>rk)l=m+1;else r=m;
	}
	int lk=0,rk=1e9;
	rep(i,1,n)if(a[i]==-1){
		if(i>1&&~a[i-1]){
			lk=max(lk,a[i-1]-m);
			rk=min(rk,a[i-1]+m);
		}
		if(i<n&&~a[i+1]){
			lk=max(lk,a[i+1]-m);
			rk=min(rk,a[i+1]+m);
		}
	}
	printf("%d %d\n",m,lk);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}