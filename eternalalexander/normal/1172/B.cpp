#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
const int mod=998244353;
int f[maxn],n,degr[maxn],ans=1;


int main(){
//	freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
	scanf("%d",&n);
	f[0]=1;for(int i=1;i<=n;++i)f[i]=(ll)f[i-1]*i%mod;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		degr[u]++;degr[v]++;
	}for(int i=1;i<=n;++i)ans=(ll)ans*f[degr[i]]%mod;
	printf("%d",(ll)ans*n%mod);
	return 0;
}