#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 1000010
using namespace std;
typedef long long ll;
struct pr{ll x,y;}a[N];
void operator +=(pr &x,pr y){x.x+=y.x;x.y+=y.y;}
ll operator *(pr x,ll y){return x.x+x.y*y;}
int n,m,l[N],r[N],s[N],t[N],p[N];
ll ans[N];vector<int>v0[N],v1[N];
void f(int x,pr y){for(;x<=n;x+=x&(-x))a[x]+=y;}
pr q(int x){pr y={0,0};for(;x;x^=x&(-x))y+=a[x];return y;}
void sol(){
	rep(i,1,n){
		v0[i].clear();v1[i].clear();
	}int k=0;
	rep(i,1,m)v0[l[i]].pb(i);
	rep(i,1,n){
		while(k&&s[t[k]]<s[i])--k;
		p[i]=t[k];t[++k]=i;
		if(p[i]){
			v1[p[i]].pb(i);f(i,{i-p[i]-1,0});
		}else f(i,{i,-1});
	}
	rep(i,1,n){f(i,{-i,1});
		for(int j:v0[i])ans[j]+=q(r[j])*i;
		for(int j:v1[i])f(j,{i+1,-1});
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&s[i]);
	rep(i,1,m)scanf("%d",&l[i]);
	rep(i,1,m){
		scanf("%d",&r[i]);ans[i]=(r[i]-l[i]+1);
	}sol();
	rep(i,1,n/2)swap(s[i],s[n-i+1]);
	rep(i,1,m){
		swap(l[i],r[i]);l[i]=n-l[i]+1;r[i]=n-r[i]+1;
	}sol();
	rep(i,1,m)printf("%lld ",ans[i]);
}