#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int val[200005];
vector<int> v[200005];
int Si[200005];
int SIZE[200005];
LL mod=1e9+7;
pii set_Si(int a,int f){
	Si[a]=0;
	SIZE[a]=1;
	for(auto it:v[a])
		if(it!=f){
			pii p=set_Si(it,a);
			Si[a]+=p.x;
			SIZE[a]+=p.y;
		}
	Si[a]=1-Si[a];
	return mp(Si[a],SIZE[a]);	
}
LL ans=0;
int n;
void dfs(int a,int f,int sum){
	int value=1-Si[a];
	LL add=0;
	for(auto it:v[a]){
		if(it!=f){
			dfs(it,a,1-sum-value+Si[it]);
			//ans+=(LL)-Si[it]*(n-SIZE[it])%mod;
			add+=(LL)-Si[it]*(n-SIZE[it])%mod;
			add%=mod;
		}
	}
	//ans+=(LL)-sum*(n-SIZE[a])%mod;
	add+=(LL)-sum*SIZE[a]%mod;
	add%=mod;
	ans+=add*val[a]%mod;
	//printf("%d %d %lld\n",sum,a,add);
	ans%=mod;
}
LL checkans=0;
void check(int a,int f,int sum,int flag){
	sum+=val[a]*flag;
	checkans+=sum;
	for(auto it:v[a]){
		if(it!=f){
			check(it,a,sum,-flag);
		}
	}
}
int main(){
	scanf("%d",&n);
	LL sum=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&val[i]),sum+=val[i];
	sum%=mod;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	set_Si(1,0);
	dfs(1,0,0);
	printf("%lld\n",((ans+(sum%mod*n)%mod)%mod+mod)%mod);
}