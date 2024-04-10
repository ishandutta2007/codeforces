#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<double,double> pr;
int n,f[N];ll a[N],b[N],c[N],ans;
vector<int>p[N];
void dp(int x){a[x]=c[x]=1;
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;dp(i);
		b[x]=(a[x]*a[i]+b[x]*(b[i]+c[i]))%mo;
		c[x]=c[x]*c[i]%mo;		
		a[x]=a[x]*(b[i]+c[i])%mo;
	}
	c[x]=(c[x]+b[x])%mo;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	dp(1);ans=1;
	for(auto i:p[1])ans=ans*c[i]%mo;
	ans=(ans+b[1])%mo;printf("%lld\n",ans);
}