#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int n;ll l[N],r[N];
pair<int,int>p[N];
void gl(int x,ll y){
	for(;x<=n;x+=x&(-x))l[x]=(l[x]+y)%mo;
}
void gr(int x,ll y){
	for(;x<=n;x+=x&(-x))r[x]=(r[x]+y)%mo;
}
ll ql(int x){ll y=0;
	for(;x;x-=x&(-x))y=(y+l[x])%mo;return y;
}
ll qr(int x){ll y=0;
	for(;x;x-=x&(-x))y=(y+r[x])%mo;return y;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i].fr);p[i].sc=i;
	}ll ans=0;
	sort(p+1,p+n+1);
	rep(i,1,n){
		ans=(ans+(1ll*p[i].sc*(n-p[i].sc+1)
		+ql(p[i].sc-1)*(n-p[i].sc+1)
		+p[i].sc*(qr(n)+mo-qr(p[i].sc)))%mo*p[i].fr)%mo;
		gl(p[i].sc,p[i].sc);gr(p[i].sc,n-p[i].sc+1);
	}
	printf("%lld\n",ans);
}