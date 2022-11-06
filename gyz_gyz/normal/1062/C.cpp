#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 300000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,a[N];char s[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	scanf("%d%d",&n,&m);scanf("%s",s+1);
	rep(i,1,n)a[i]=a[i-1]+(s[i]=='1');
	rep(i,1,m){int l,r,x,y;
		scanf("%d%d",&l,&r);
		x=a[r]-a[l-1];y=r-l+1-x;
		printf("%lld\n",(qk(2,x)+mo-1)*qk(2,y)%mo);
	}
}