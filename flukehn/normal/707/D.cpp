#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=1e9+7;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
mt19937 rnd(time(0));

const int N=1e5+11;
int n,m,q;
int a[1011][1011],nu[1011],re[1011],tot;
int op[N],u[N],v[N];
vector<int> e[N];
int ans[N];
void rev(int x,int y){
	if(a[x][y]^re[x])tot--,nu[x]--;
	else tot++,nu[x]++;
	a[x][y]^=1;
}
void rev(int x){
	re[x]^=1;
	tot-=nu[x];
	nu[x]=m-nu[x];
	tot+=nu[x];
}
int nd(int x){
	if(op[x]<1||op[x]>3)return 0;
	if(op[x]==3)return 1;
	return (re[u[x]]^a[u[x]][v[x]])==(op[x]-1);
}
void wk(int x,int w=0){
	if(op[x]<=2){
		rev(u[x],v[x]);	
	}else{
		rev(u[x]);
	}
}
void dfs(int x){
	int w=nd(x);
	if(w)wk(x);
	//cerr<<"x: "<<x<<"\n";
	//For(i,1,n+1)cerr<<re[i]<<" \n"[i==n];
	//For(i,1,n+1)For(j,1,m+1)cerr<<(a[i][j]^re[i])<<" \n"[j==m];
	ans[x]=tot;
	for(int y:e[x])dfs(y);
	if(w)wk(x,1);
}
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	For(i,1,q+1){
		cin>>op[i]>>u[i];
		if(op[i]<=2)cin>>v[i];
		if(op[i]==4)e[u[i]].pb(i);
		else e[i-1].pb(i);
	}
	dfs(0);
	For(i,1,q+1)cout<<ans[i]<<"\n";
}