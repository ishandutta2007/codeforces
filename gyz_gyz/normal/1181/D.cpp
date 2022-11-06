#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=998244353;
int s[N],ans[N];pair<ll,int>a[N],qs[N];
void f(int x,int y,int l,int r){
	++s[x];if(l==r)return;int m=(l+r)>>1;
	if(y<=m)f(x<<1,y,l,m);else f(x<<1|1,y,m+1,r);
}
int q(int x,int y,int l,int r){
	if(l==r)return l;int m=(l+r)>>1;
	if(y<=s[x<<1])return q(x<<1,y,l,m);
	return q(x<<1|1,y-s[x<<1],m+1,r);
}
int main(){ll n;int m,Q;
	scanf("%lld%d%d",&n,&m,&Q);
	rep(i,1,n){int x;
		scanf("%d",&x);++a[x].fr;
	}
	rep(i,1,m)a[i].sc=i;
	sort(a+1,a+m+1);
	rep(i,1,Q){
		scanf("%lld",&qs[i].fr);
		qs[i].sc=i;
	}ll h=0;int x=0;
	sort(qs+1,qs+Q+1);
	rep(i,1,Q){
		while(x<m&&(a[x+1].fr-h)*x+n<qs[i].fr){
			n+=(a[x+1].fr-h)*x;h=a[x+1].fr;
			while(x<m&&a[x+1].fr==h)f(1,a[++x].sc,1,m);
		}
		ans[qs[i].sc]=q(1,(qs[i].fr-n-1)%x+1,1,m);
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
}