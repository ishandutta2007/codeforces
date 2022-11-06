#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define N 500010
using namespace std;
typedef long long ll;
struct pr{int x;ll w0,w1;};
vector<pr>p[N];
struct dd{
	ll p00,p01,p10,p11;
	dd(){p00=p01=p10=p11=0;}
}d[20][N];
int n,q,h[N],f[20][N];ll w[N];
struct cmp{
	bool operator ()(int x,int y){
		return w[x]!=w[y]?x<y:w[x]<w[y];
	}
};
set<int,cmp>s;
dd operator +(dd a,dd b){dd c;
	c.p00=min(a.p00+b.p00,a.p01+b.p10);
	c.p01=min(a.p00+b.p01,a.p01+b.p11);
	c.p10=min(a.p10+b.p00,a.p11+b.p10);
	c.p11=min(a.p10+b.p01,a.p11+b.p11);return c;
}
dd operator ~(dd a){swap(a.p10,a.p01);return a;}
void dfs(int x){
	for(auto i:p[x])if(i.x!=f[0][x]){
		h[i.x]=h[x]+1;f[0][i.x]=x;dfs(i.x);
		d[0][i.x].p00=min(i.w0,i.w1+w[x]+w[i.x]);
		d[0][i.x].p01=min(i.w0+w[x],i.w1+w[i.x]);
		d[0][i.x].p10=min(i.w1+w[x],i.w0+w[i.x]);
		d[0][i.x].p11=min(i.w1,i.w0+w[x]+w[i.x]);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&w[i]);
	rep(i,1,n-1){int x,y;ll w0,w1;
		scanf("%d%d%lld%lld",&x,&y,&w0,&w1);
		p[x].pb({y,w0,w1});p[y].pb({x,w0,w1});
	}
	rep(i,1,n)s.insert(i);
	while(!s.empty()){
		int x=*s.begin();s.erase(s.begin());
		for(auto i:p[x])if(w[i.x]>w[x]+i.w0+i.w1){
			s.erase(i.x);w[i.x]=w[x]+i.w0+i.w1;s.insert(i.x);
		}
	}
	f[1][0]=1;dfs(1);
	rep(i,1,19)rep(j,1,n){
		int x=f[i-1][j];f[i][j]=f[i-1][x];
		d[i][j]=d[i-1][j]+d[i-1][x];
	}
	scanf("%d",&q);
	while(q--){int X,Y;
		scanf("%d%d",&X,&Y);
		int x=(X+1)/2,y=(Y+1)/2;dd ld,rd;
		if(h[x]<h[y]){swap(x,y);swap(X,Y);}
		ld.p01=ld.p10=w[x];rd.p01=rd.p10=w[y];
		dep(i,19,0)if((h[x]-h[y])>>i){
			ld=ld+d[i][x];x=f[i][x];
		}
		dep(i,19,0)if(f[i][x]!=f[i][y]){
			ld=ld+d[i][x];rd=~d[i][y]+rd;
			x=f[i][x];y=f[i][y];
		}
		if(x!=y){
			ld=ld+d[0][x];rd=~d[0][y]+rd;
		}
		if(X&1){
			if(Y&1)printf("%lld\n",(ld+rd).p00);
			else printf("%lld\n",(ld+rd).p01);
		}else if(Y&1)printf("%lld\n",(ld+rd).p10);
		else printf("%lld\n",(ld+rd).p11);
	}
}