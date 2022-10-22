#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
inl int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
ll n,m,q,sizen,sizem;
inline ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	cin>>n>>m>>q;
	sizen=n/gcd(n,m);
	sizem=m/gcd(n,m);
	while(q--){
		ll a1,a2,b1,b2;
		scanf("%lld%lld%lld%lld",&a1,&a2,&b1,&b2);a2--,b2--;
		if(a1==1) a2/=sizen;
		if(a1==2) a2/=sizem;
		if(b1==1) b2/=sizen;
		if(b1==2) b2/=sizem;
		if(a2==b2) puts("YES");
		else puts("NO");
	}
	return 0;
}