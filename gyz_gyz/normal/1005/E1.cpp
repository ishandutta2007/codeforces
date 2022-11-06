#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define ll long long
#define N 1048576
#define inf 1000000000
using namespace std;
int n,m,x,p1[N],p2[N],L[N*2],R[N*2],a[N*2];ll ans;
struct pr{int x,y;}p[N];
bool cmp(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;else return x.x<y.x;
}
void ins(int x,int y){
	if((y==L[x])&&(y==R[x])){
		a[x]++;return;
	}
	if(y<=R[x*2])ins(x*2,y);else ins (x*2+1,y);
	a[x]=a[x*2]+a[x*2+1];
}
int f(int x,int l,int r){
	if((l==L[x])&&(r==R[x]))return a[x];
	if(r<=R[x*2])return f(x*2,l,r);
	if(l>R[x*2])return f(x*2+1,l,r);
	return f(x*2,l,R[x*2])+f(x*2+1,L[x*2+1],r);
}
int main(){
	L[1]=1;R[1]=N;
	rep(i,1,N-1){
		L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
		L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
	}
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&x);
		p1[i]=p1[i-1]+(x<m);
		p2[i]=p2[i-1]+(x>m);
	}
	rep(i,0,n){
		p[i].x=i-p2[i]*2;
		p[i].y=i-p1[i]*2+n*2;
	}
	sort(p,p+n+1,cmp); 
	rep(i,0,n){
		ans+=f(1,1,p[i].y-1);
		ins(1,p[i].y);
	}
	printf("%I64d\n",ans);
}