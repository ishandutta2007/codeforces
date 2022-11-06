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
const int N=3e5+11;
mt19937 rnd(time(0));
int n,m;
vector<int> e[N];
int a[N],b[N],c[N];
void dfs(int x){
	b[x]=1;
	int flag=0;
	for(int y:e[x]){
		if(a[y])flag=1;
	}
	if(!flag)a[x]=1;
	for(int y:e[x])if(!b[y]){
		dfs(y);
	}
}
void Dfs(int x){
	c[x]=1;
	for(int y:e[x])if((a[x]||a[y])&&!c[y])Dfs(y);
}
int work(){
	for(int i=1;i<=n;++i)a[i]=b[i]=0;
	for(int i=1;i<=n;++i)random_shuffle(e[i].begin(),e[i].end());
	int p=rnd()%n+1;
	dfs(p);
	for(int i=1;i<=n;++i)c[i]=0;
	Dfs(p);
	for(int i=1;i<=n;++i)if(!c[i])return 0;
	return 1;
}
int ans[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)e[i].clear();
		For(i,0,m){
			int x,y;
			cin>>x>>y;
			e[x].pb(y);
			e[y].pb(x);
		}
		int flag=0;
		For(i,0,20)if(work()){flag=1;break;}
		if(!flag)puts("NO");
		else{
			puts("YES");
			int t=0;
			for(int i=1;i<=n;++i)if(a[i])ans[++t]=i;
			printf("%d\n",t);
			for(int i=1;i<=t;++i)printf("%d%c",ans[i]," \n"[i==t]);
		}
	}
}