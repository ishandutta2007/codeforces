
 #include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 300000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int m;ll ans,x,n,s,a[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	scanf("%I64d%d%I64d",&n,&m,&s);ans=1;
	rep(i,1,m){
		scanf("%I64d",&a[i]);x=a[i]-a[i-1];
		ans=ans*((qk(s,x*2)+qk(s,x))*qk(2,mo-2)%mo)%mo;
	}
	ans=ans*qk(s,n-a[m]*2)%mo;
	printf("%I64d",ans);
}