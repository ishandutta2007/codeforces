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
#define N 10010
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m;vector<int>a[N],b[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){int x;
		scanf("%d",&x);
		a[i+j].pb(x);
	}
	rep(i,1,n)rep(j,1,m){int x;
		scanf("%d",&x);
		b[i+j].pb(x);
	}
	rep(i,2,n+m){int k=a[i].size();
		sort(a[i].begin(),a[i].end());
		sort(b[i].begin(),b[i].end());
		rep(j,0,k-1)if(a[i][j]!=b[i][j])return printf("NO\n"),0;
	}
	printf("YES\n");
}