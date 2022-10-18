#include <bits/stdc++.h>
#define maxn 3005
typedef long long ll;
const int mod=1e9+7;
int f[maxn][maxn],n,d,fa[maxn];
std::vector<int>ch[maxn];

int qpow(int a,int b){
	if (b==0)return 1;
	ll d=qpow(a,b>>1);d=d*d%mod;
	if(b&1)d=d*a%mod;
	return d;
}

int inv(int x){return qpow(x,mod-2);}

int lagrange_interpolation(int k,int *a){
	int ans=0;
	for(int i=0;i<=n;++i){
		int sum=a[i],sum2=1;
	 	for(int j=0;j<=n;++j){
	 		if(i==j)continue;
	 		sum=(ll)sum*((k-j+mod)%mod)%mod;
	 		sum2=(ll)sum2*((i-j+mod)%mod)%mod;
	 	}ans=(ans+(ll)sum*inv(sum2)%mod)%mod;
	}return ans;
}

void dfs(int u){
	for(int i=1;i<=n;++i)f[u][i]=1;
	for(int v:ch[u]){
		dfs(v);
		for(int i=1;i<=n;++i)
			f[u][i]=(ll)f[u][i]*f[v][i]%mod;
	}for(int i=1;i<=n;++i)f[u][i]=(f[u][i]+f[u][i-1])%mod;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=2;i<=n;++i){
		scanf("%d",&fa[i]);
		ch[fa[i]].push_back(i);
	}dfs(1);
	std::cout<<lagrange_interpolation(d,f[1]);
	return 0;
}