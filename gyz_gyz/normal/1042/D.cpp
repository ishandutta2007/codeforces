#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define M 15000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 200000000000000ll
#define eps 1e-8
using namespace std;
int n,tot,ls[M],rs[M],s[M];ll a[N],t,ans;
void f(int x,ll y,ll L,ll R){
	s[x]++;if((L==y)&&(R==y))return;
	if(!ls[x])ls[x]=++tot,rs[x]=++tot;ll rr=L+(R-L)/2;
	if(y<=rr)f(ls[x],y,L,rr);else f(rs[x],y,rr+1,R);
}
ll q(int x,ll l,ll r,ll L,ll R){
	if((l==L)&&(r==R))return s[x];if(!ls[x])return 0;
	ll rr=L+(R-L)/2;
	if(r<=rr)return q(ls[x],l,r,L,rr);
	else if(l>rr)return q(rs[x],l,r,rr+1,R);
	else return q(ls[x],l,rr,L,rr)+q(rs[x],rr+1,R,rr+1,R);
}
int main(){
	scanf("%d%I64d",&n,&t);
	rep(i,1,n){
		scanf("%I64d",&a[i]);a[i]+=a[i-1];
	}
	tot=1;f(1,0,-Inf,Inf);
	rep(i,1,n){
		ans+=q(1,max(-Inf,min(Inf,a[i]-t+1)),Inf,-Inf,Inf);
		f(1,a[i],-Inf,Inf);
	}
	printf("%I64d\n",ans);
}