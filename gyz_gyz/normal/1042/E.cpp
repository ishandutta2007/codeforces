#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000
#define ll long long
#define mo 998244353
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
ll f[N*N],d1,d2,d3,d4;int n,m,x,y,ls,a[N][N];
struct pr{int x,y;}id[N*N];
bool cmp(pr x,pr y){return a[x.x][x.y]<a[y.x][y.y];}
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m){
		scanf("%d",&a[i][j]);
		id[m*(i-1)+j]={i,j};
	}
	scanf("%d%d",&x,&y);
	sort(id+1,id+n*m+1,cmp);ls=1;
	rep(i,1,n*m){
		if(i&&cmp(id[i-1],id[i]))
			for(;ls<i;ls++){
				add(d1,id[ls].x*id[ls].x+id[ls].y*id[ls].y+f[ls]);
				add(d2,2*(mo-id[ls].x));add(d3,2*(mo-id[ls].y));d4++;
			}
		f[i]=(d1+d2*id[i].x+d3*id[i].y+d4*(id[i].x*id[i].x+id[i].y*id[i].y))%mo*qk(ls-1,mo-2)%mo;
		if((id[i].x==x)&&(id[i].y==y)){printf("%I64d",f[i]);return 0;}
	}
}