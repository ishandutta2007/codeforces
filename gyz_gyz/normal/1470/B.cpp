#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
int a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		rep(j,2,a[i]){
			if(j*j>a[i])break;
			while(!(a[i]%(j*j)))a[i]/=j*j;
		}
	}
	sort(a+1,a+n+1);int cnt=0,an0=0,an1=0;
	rep(i,1,n){++cnt;
		if(i==n||a[i]!=a[i+1]){
			an0=max(an0,cnt);
			if(a[i]==1||!(cnt&1))an1+=cnt;
			cnt=0;
		}
	}
	an1=max(an1,an0);
	int q;scanf("%d",&q);
	rep(i,1,q){ll x;
		scanf("%lld",&x);
		printf("%d\n",x?an1:an0);
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}