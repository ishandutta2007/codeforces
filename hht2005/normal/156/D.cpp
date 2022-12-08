#include<bits/stdc++.h>
using namespace std;
int mod;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int N=1e5+10;
vector<int>S[N];
int f[N],cnt=0;
void dfs(int x) {
	f[x]=1;
	cnt++;
	for(int y:S[x])
		if(!f[y])dfs(y);
}
int main() {
	int n,m,a,b;
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	int sum=1,k=0;
	for(int i=1;i<=n;i++)
		if(!f[i]) {
			dfs(i);
			sum=1ll*sum*cnt%mod;
			cnt=0;
			k++;
		}
	if(k==1)printf("%d\n",1%mod);
	else printf("%lld\n",1ll*sum*qpow(n,k-2)%mod);
	return 0; 
}