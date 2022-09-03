#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<int> v[200005];
LL fra[300005];
int mod=998244353;
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
LL ans;
void dfs(int x,int f){
	int cnt=0;
	for(auto it:v[x]){
		if(it!=f){
			cnt++;
			dfs(it,x);
			if(v[it].size()!=1){
				ans*=2;
				ans%=mod;
			}
		}
	}
	ans*=fra[cnt];
	ans%=mod;
}
int main(){
	fra[0]=1;
	for(int i=1;i<300005;i++){
		fra[i]=fra[i-1]*i%mod;
	}
	ans=1;
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i = 1;i<=n;i++){
		ans*=fra[v[i].size()];
		ans%=mod;
	}
	ans*=n;
	ans%=mod;
	printf("%lld\n",ans%mod);
}