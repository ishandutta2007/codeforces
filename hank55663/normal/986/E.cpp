#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
vector<int> v[100005];
int p[100005][20];
int d[100005];
void dfs(int a,int f,int dep){
	p[a][0]=f;
	d[a]=dep;
	for(int j=1;j<20;j++)
	p[a][j]=p[p[a][j-1]][j-1];
	for(auto it:v[a]){
		if(it!=f){
			dfs(it,a,dep+1);
		}
	}
}
int getLCA(int a,int b){
	if(d[a]>d[b])
	swap(a,b);
	int x=d[b]-d[a];
	for(int i=0;i<20;i++){
		if(x&(1<<i)){
			b=p[b][i];
		}
	}
	if(a==b)
	return a;
	for(int i=1;i<20;i++){
		if(p[b][i]==p[a][i])
		return getLCA(p[b][i-1],p[a][i-1]);
	}
}
int A[100005];
LL ans[100005];
vector<pii> que[100005];
map<int,map<int,int> > cnt;
int prime[10000005];
int find(){
	MEM(prime);
	for(int i=2;i<=10000000;i++){
		if(!prime[i]){
			for(int j=i;j<=10000000;j+=i)
				prime[j]=i;
		}
	}
}
LL mod=1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
void dfs2(int a,int f){
	LL x=A[a];
	map<int,int> m;
	while(x!=1){
		m[prime[x]]++;
		x/=prime[x];
	}
	for(auto it:m){
		cnt[it.x][it.y]++;
	}
	for(auto it:que[a]){
		map<int,int> mm;
		int k=abs(it.y);
		while(k!=1){
			mm[prime[k]]++;
			k/=prime[k];
		}
		LL res=1;
		for(auto it2:mm){
			int tot=0;
			for(auto it3:cnt[it2.x]){
				tot+=min(it2.y,it3.x)*it3.y;
			}
			res*=f_pow(it2.x,tot);
			res%=mod;
		}
		//printf("%d %d %lld\n",it.x,it.y,res);
		if(it.y<0){
			ans[it.x]*=f_pow(res,mod-2);
			ans[it.x]%=mod;
			ans[it.x]*=f_pow(res,mod-2);
			ans[it.x]%=mod;
			ans[it.x]*=__gcd(A[a],-it.y);
			ans[it.x]%=mod;
		}
		else{
			ans[it.x]*=res;
			ans[it.x]%=mod;
		}
	}
	for(auto it:v[a]){
		if(it!=f){
			dfs2(it,a);
		}
	}
	for(auto it:m){
		cnt[it.x][it.y]--;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	MEM(p);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int u,v,x;
		scanf("%d %d %d",&u,&v,&x);
		que[u].pb(mp(i,x));
		que[v].pb(mp(i,x));
		que[getLCA(u,v)].pb(mp(i,-x));
		ans[i]=1;
	}
	find();
	dfs2(1,0);
	for(int i=0;i<q;i++)
	printf("%lld\n",ans[i]);
}