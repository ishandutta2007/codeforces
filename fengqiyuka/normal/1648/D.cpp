#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
const int N=5e5+100;
int a[5][N];
vector<int> B[N],C[N];

struct ques{
	int l,r,c;
}g[N];

multiset<ll> S;
multiset<ll>::iterator iter;
vector<ll> G[N];
ll qz[5][N],p[N],w[N];

ll mymax(ll x,ll y) {return (x>y?x:y);}

void solve(int l,int r,ll Wow){
	
	for(auto y:C[r]){
		if(g[y].l<=l){
			if(Wow<-g[y].c) Wow=-g[y].c;
		}
	}
	
	for(auto y:B[l]){
		if(g[y].r>=r){
			if(Wow<-g[y].c) Wow=-g[y].c;
		}
	}
	
	if(l==r){
		if(w[l]<Wow+p[l]) w[l]=Wow+p[l];
		return ;
	}
	
	int mid=(l+r)>>1;
	ll Max=-1e18,Le=-1e18,Re=-1e18;
	for(int i=mid;i>=l;i--){
		if(Max<p[i]) Max=p[i];
		for(auto y:B[i]){
			if(g[y].r>=r){
				if(w[r]<Max-g[y].c)
					w[r]=Max-g[y].c;
				if(Le<-g[y].c) Le=-g[y].c;
			}
			else if(g[y].r>mid){
				if(w[g[y].r]<Max-g[y].c)
					w[g[y].r]=Max-g[y].c;
			}
		}
	}
	ll Max2=-1e18;
	for(int i=r;i>=mid+1;i--){
		if(w[i]<Max2) w[i]=Max2;
		for(auto y:C[i]){
			if(g[y].l<=l){
				if(w[i]<Max-g[y].c) w[i]=Max-g[y].c;
				if(Re<-g[y].c) Re=-g[y].c;
			}
		}
		if(w[i]<Max+Wow) w[i]=Max+Wow;
		if(Max2<w[i]) Max2=w[i];
	}
	
	solve(l,mid,mymax(Wow,Re));
	solve(mid+1,r,mymax(Wow,Le));
}

int main() 
{
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&g[i].l,&g[i].r,&g[i].c);
		B[g[i].l].push_back(i);
		C[g[i].r].push_back(i);
	}
	
	ll Sum=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++) qz[i][j]=qz[i][j-1]+a[i][j];
	
	ll Max=0;
	for(int i=n;i>=1;i--){
		ll t=qz[1][i]-qz[2][i-1];
		p[i]=t;
	}
	
	memset(w,-60,sizeof(w));
	solve(1,n,-1e18);
	
	for(int i=1;i<=n;i++){
		iter=S.end();
		if(!S.empty()){
			iter--;
			ll t=(*iter);
			if(w[i]<t) w[i]=t;
		}
		for(auto y:B[i+1]){
			G[g[y].r].push_back(w[i]-g[y].c);
			S.insert(w[i]-g[y].c);
		}
		for(auto y:G[i]){
			iter=S.find(y);
			S.erase(iter);
		}
	}
	
	ll Ans=-1e18;
	for(int i=1;i<=n;i++){
		ll t=w[i]+qz[2][i]+qz[3][n]-qz[3][i-1];
		if(Ans<t) Ans=t;
	}
	
	printf("%lld\n",Ans);
	return 0;
}