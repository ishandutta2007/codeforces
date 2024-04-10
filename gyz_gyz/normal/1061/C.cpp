#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 2000000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll ans,f[N];vector<int>a[N];
int main(){
	dep(i,1000000,1)rep(j,1,1000000/i)a[i*j].pb(i);
	scanf("%d",&n);f[0]=1;
	rep(i,1,n){
		int x;scanf("%d",&x);
		for(auto j:a[x])f[j]=(f[j]+f[j-1])%mo;
	}
	rep(i,1,n)ans=(ans+f[i])%mo;printf("%lld\n",ans);
}