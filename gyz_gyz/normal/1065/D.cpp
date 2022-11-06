#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 2000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
const int u1[8]={1,2,2,1,-1,-2,-2,-1};
const int u2[8]={2,1,-1,-2,-2,-1,1,2};
int n,s,t,dl[N],a[20][20];
vector<int>p[N];
struct pr{int x,y;}ans,d[N];
bool operator <(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;return x.x<y.x;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
	rep(i,1,n*n){
		p[i].pb(i+n*n);p[i].pb(i+n*n*2);
		p[i+n*n].pb(i);p[i+n*n].pb(i+n*n*2);
		p[i+n*n*2].pb(i);p[i+n*n*2].pb(i+n*n);
	}
	rep(i,1,n)rep(j,1,n){
		rep(k,0,8){
			int i1=i+u1[k],j1=j+u2[k];
			if((i1<1)||(i1>n)||(j1<1)||(j1>n))continue;
			p[a[i][j]].pb(a[i1][j1]);
		}
		rep(k,1,n)if(k!=i){
			int r=k+j-i;
			if((r<1)||(r>n))continue;
			p[a[i][j]+n*n].pb(a[k][r]+n*n);
		}
		rep(k,1,n)if(k!=i){
			int r=i+j-k;
			if((r<1)||(r>n))continue;
			p[a[i][j]+n*n].pb(a[k][r]+n*n);
		}
		rep(k,1,n)if(k!=i)
			p[a[i][j]+n*n*2].pb(a[k][j]+n*n*2);
		rep(k,1,n)if(k!=j)
			p[a[i][j]+n*n*2].pb(a[i][k]+n*n*2);
	}
	rep(i,1,n*n-1){s=t=0;
		rep(j,1,n*n*3)if(j%(n*n)!=i)d[j]={inf,inf};
		else dl[++t]=j;
		for(;s<=t;s++)for(auto i:p[dl[s]]){
			if(d[i].x==inf)dl[++t]=i;
			pr r=d[dl[s]];r.x++;
			if(!(abs(dl[s]-i)%(n*n)))r.y++;
			if(r<d[i])d[i]=r;
		}
	}ans={inf,inf};
	rep(i,1,3)if(d[n*n*i]<ans)ans=d[n*n*i];
	printf("%d %d",ans.x,ans.y);
}