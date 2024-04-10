#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define N 500010
using namespace std;
typedef long long ll;
struct pr{int x,y;}a[N];
bool operator <(pr a,pr b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int n,rc[N],f[N],nt[N];set<pr>sx[N],sy[N];
ll an,w[N],h[N],ans[N];bool v[N];
int gf(int x){
	return f[x]==x?x:gf(f[x]);
}
void ins(int x){
	int dx=sy[a[x].y].empty()?0:gf(sy[a[x].y].begin()->y);
	int dy=sx[a[x].x].empty()?0:gf(sx[a[x].x].begin()->y);
	if(dx&&dx==dy)return;v[x]=1;
	sx[a[x].x].insert({a[x].y,x});
	sy[a[x].y].insert({a[x].x,x});
	int r=x;++an;
	if(dx){
		f[x]=dx;an+=h[dx]-1;++w[dx];r=dx;
	}
	if(dy){
		an+=(w[dy]-1)*h[r]+(w[r]-1)*h[dy];
		if(w[r]+h[r]>w[dy]+h[dy]){
			rc[x]=dy;f[dy]=r;
			w[r]+=w[dy]-1;h[r]+=h[dy];
		}else{
			rc[x]=r;f[r]=dy;
			w[dy]+=w[r]-1;h[dy]+=h[r];
		}
	}
}
void del(int x){--an;v[x]=0;
	sx[a[x].x].erase({a[x].y,x});
	sy[a[x].y].erase({a[x].x,x});
	if(rc[x]){
		int r=f[rc[x]];f[rc[x]]=rc[x];
		w[r]-=w[rc[x]]-1;h[r]-=h[rc[x]];
		an-=(w[r]-1)*h[rc[x]]+(w[rc[x]]-1)*h[r];rc[x]=0;
	}
	if(f[x]!=x){
		--w[f[x]];an-=h[f[x]]-1;f[x]=x;
	}
}
void sol(int l,int r){
	if(l==r){
		if(nt[l]>l)ins(l);ans[l]=an;
		if(v[l])del(l);return;
	}
	int m=(l+r)/2;
	rep(i,m+1,r)if(nt[i]<l)ins(i);
	sol(l,m);
	dep(i,r,m+1)if(v[i])del(i);
	rep(i,l,m)if(nt[i]>r)ins(i);
	sol(m+1,r);
	dep(i,m,l)if(v[i])del(i);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
	rep(i,1,n)f[i]=i,w[i]=h[i]=1;
	map<pr,int>mp;
	rep(i,1,n){
		if(mp.count(a[i])){
			nt[i]=mp[a[i]];
			nt[mp[a[i]]]=i;
			mp.erase(a[i]);
		}else mp[a[i]]=i;
	}
	rep(i,1,n)if(!nt[i])nt[i]=n+1;sol(1,n);
	rep(i,1,n)printf("%lld ",ans[i]);
}