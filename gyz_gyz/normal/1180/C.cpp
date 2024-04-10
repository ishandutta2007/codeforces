#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int a[N],r1[N],r2[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	deque<int>d;
	rep(i,1,n){int x;
		scanf("%d",&x);d.pb(x);
	}
	rep(i,1,n-1){
		r1[i]=d.front();d.pop_front();
		r2[i]=d.front();d.pop_front();
		d.pb(min(r1[i],r2[i]));
		d.push_front(max(r1[i],r2[i]));
	}
	rep(i,1,n){
		a[i]=d.front();d.pop_front();
	}
	rep(i,1,m){ll x;
		scanf("%lld",&x);
		if(x<=n-1)printf("%d %d\n",r1[x],r2[x]);
		else printf("%d %d\n",a[1],a[(x-1)%(n-1)+2]);
	}
}