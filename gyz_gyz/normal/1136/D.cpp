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
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];bool v[N];vector<int>p[N];
int main(){int n,m,tot=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);
	}
	v[a[n]]=1;tot=1;
	dep(i,n-1,1){
		int ct=0;
		for(auto j:p[a[i]])if(v[j])++ct;
		if(ct<tot)v[a[i]]=1,++tot;
	}
	printf("%d\n",n-tot);
}