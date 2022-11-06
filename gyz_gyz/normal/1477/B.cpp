#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
const ll inf=1e18;
char s1[N],s2[N];
int lq[N],rq[N],a[N*4],lz[N*4];
void dw(int x,int L,int R){
	int m=(L+R)>>1;
	if(~lz[x]){
		lz[x<<1]=lz[x<<1|1]=lz[x];
		a[x<<1]=lz[x]*(m-L+1);
		a[x<<1|1]=lz[x]*(R-m);
		lz[x]=-1;
	}
}
void cg(int x,int l,int r,int y,int L,int R){
	if(l<=L&&r>=R){
		a[x]=y*(R-L+1);lz[x]=y;return;
	}
	int m=(L+R)>>1;dw(x,L,R);
	if(l<=m)cg(x<<1,l,r,y,L,m);
	if(r>m)cg(x<<1|1,l,r,y,m+1,R);
	a[x]=a[x<<1]+a[x<<1|1];
}
int q(int x,int l,int r,int L,int R){
	if(l<=L&&r>=R)return a[x];
	int m=(L+R)>>1;dw(x,L,R);
	return (l<=m?q(x<<1,l,r,L,m):0)+(r>m?q(x<<1|1,l,r,m+1,R):0);
}
void sol(){int n,m;
	scanf("%d%d%s%s",&n,&m,s1+1,s2+1);
	rep(i,1,n)cg(1,i,i,s2[i]-'0',1,n);
	rep(i,1,m)scanf("%d%d",&lq[i],&rq[i]);
	dep(i,m,1){
		int x=q(1,lq[i],rq[i],1,n),y=rq[i]-lq[i]+1;
		if(!x||x==y)continue;
		if(x*2==y){
			printf("NO\n");return;
		}
		cg(1,lq[i],rq[i],x*2<y?0:1,1,n);
	}
	rep(i,1,n)if(q(1,i,i,1,n)!=s1[i]-'0'){
		printf("NO\n");return;
	}
	printf("YES\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}