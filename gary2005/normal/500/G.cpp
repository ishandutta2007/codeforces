/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=2e5+233;
int n;
vector<int> g[MAXN];
int t,fa[MAXN][18],depth[MAXN];
int getk(int u,int k){
	rep(i,18) if((k>>i)&1) u=fa[u][i];
	return u;
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	u=getk(u,depth[u]-depth[v]);
	if(u==v) return u;
	rl(i,17,0) if(fa[u][i]!=fa[v][i]){
		u=fa[u][i];
		v=fa[v][i];
	}
	return fa[u][0];
}
int dis(int u,int v){
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void dfs(int now,int pre){
	fa[now][0]=pre;
	rb(i,1,17) fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto it:g[now]) if(it!=pre) depth[it]=depth[now]+1,dfs(it,now);
}
LL exgcd(LL a, LL b, LL& x, LL& y) {
  // ax+by=gcd(a,b) 
  x = 1, y = 0;
  LL x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
LL f(LL l,LL r,LL a,LL b){
	if(l>r) return 1e18;
	a%=b;
	// l<=xa<=r (mod b)
	if(a==0) return 1e18;
	if((l-1)/a!=r/a) return (l+a-1)/a;
	LL ans=f((a-r%a)%a,(a-l%a)%a,b%a,a);
	if(ans==1e18) return 1e18;
	return (ans*b+l+a-1)/a;
}
bool onpath(int u,int v,int x){
	return dis(u,v)==dis(u,x)+dis(v,x);
}
void extend(mp & p,int X,int u,int v,int x,int y){
	if(!onpath(u,v,X)||!onpath(x,y,X)) return ;
	if(p.FIR==-1){
		p=II(X,X);
		return ;
	}
	if(onpath(p.FIR,p.SEC,X)) return ;
	if(onpath(p.FIR,X,p.SEC)) p.SEC=X;
	else p.FIR=X;
}
mp work(int u,int v,int x,int y){
	int a[4]={u,v,x,y};
	int b[16];
	rep(i,4) rep(j,4) b[i*4+j]=lca(a[i],a[j]);
	mp ans=II(-1,-1);
	rep(i,16) extend(ans,b[i],u,v,x,y);
	return ans;
}
LL mylcm(LL A,LL B){return A*B/__gcd(A,B);}
LL calc1(int c1,int c2,int D1,int D2){
	// c1+yD1=c2+xD2
	// +lcm(D1,D2)
//	cout<<c1<<' '<<c2<<" "<<D1<<" "<<D2<<endl;
	LL x,y;
	if(abs(c1-c2)%__gcd(D1,D2)) return 1e18;
	LL tmp=(c1-c2)/__gcd(D1,D2);
	exgcd(D2,D1,x,y);
	y=-y;
	x*=tmp;
	y*=tmp;
	assert(y*D1+c1==x*D2+c2);
//	cout<<y*D1+c1<<' '<<x*D2+c2<<' '<<x<<' '<<y<<" "<<c1<<" "<<c2<<endl;
	LL Tmp=y*D1+c1;
	LL lcm_=mylcm(D1,D2);
	Tmp%=lcm_;
	if(Tmp<0){
		Tmp+=lcm_;
	}
//	cout<<"!"<<u<<" "<<v<<" "<<c1<<" "<<c2<<" "<<D1<<" "<<D2<<' '<<lcm_<<' '<<Tmp<<endl;
	return Tmp;
}
LL calc2(LL D1,LL D2,LL T1,LL T2,LL D){
//	cout<<D1<<" "<<D2<<" "<<T1<<" "<<T2<<' '<<D<<endl;
	if((D+T1+T2)&1) return 1e18;
	LL x;
	LL l,r;
	l=((T2-T1-D)%D2+D2)%D2;
	r=((T2-T1+D)%D2+D2)%D2;
	if(l==0||2*D==D2||l>r) x=0;
	else x=f(l,r,D1,D2);
	if(x==1e18) return 1e18;
	LL y=(x*D1+T1-T2+D)/D2;
	return (x * D1 + y * D2 + T1 + T2 + D) / 2;
}
/*
10
8 7
7 6
4 3
8 9
4 5
10 9
3 2
2 1
5 6
1
1 10 5 7

*/
LL query(int u,int v,int x,int y){
	mp c=work(u,v,x,y);
//	cout<<c.FIR<<" "<<c.SEC<<endl;
	if(c.FIR==-1) return -1;
	LL ans=1e18;
	int D1,D2;
	D1=dis(u,v)*2;
	D2=dis(x,y)*2;
	int D=dis(c.FIR,c.SEC);
	int U1 = dis(u, c.FIR), U2 = dis(u, c.SEC);
	if (U1 < U2) U2 = D1 - U2;
	else U1 = D1 - U1;
	int X1 = dis(x, c.FIR), X2 = dis(x, c.SEC);
	if (X1 < X2) X2 = D2 - X2;
	else X1 = D2 - X1;
	check_min(ans,calc1(U1,X1,D1,D2));
	check_min(ans,calc1(U2,X2,D1,D2));
	check_min(ans,calc2(D1,D2,U1,X2,D));
	check_min(ans,calc2(D1,D2,U2,X1,D));
//	cout<<ans<<endl;
	if(ans==1e18) return -1;
	return ans;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	scanf("%d",&t);
	rb(i,1,t){
		int u,v,x,y;
		scanf("%d%d%d%d",&u,&v,&x,&y);
		printf("%lld\n",query(u,v,x,y));
	}
	return 0;
}