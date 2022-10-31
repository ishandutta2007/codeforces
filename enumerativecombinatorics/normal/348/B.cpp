#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int b[100010];
vector<int> g[100010];
long long dp1[100010];
long long dp2[100010];
long long gcd(long long a,long long b){
	while(b){
		a%=b;
		long long c=a;
		a=b;
		b=c;
	}
	return a;
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
long long INF=10000000000000LL;
void dfs(int a,int b){
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]!=b)dfs(g[a][i],a);
	}
	if(a&&g[a].size()==1){
		return ;
	}
	long long now=1;
	bool dame=false;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		long long t=gcd(now,dp2[g[a][i]]);
		if(INF/now+1<dp2[g[a][i]]/t){
			dame=true;
			break;
		}
		now=lcm(now,dp2[g[a][i]]);
	}
	if(dame){
		dp1[a]=dp2[a]=-1;
		return ;
	}
	int d=g[a].size();
	if(a)d--;
	dp2[a]=now*d;
	long long K=INF;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		K=min(K,dp1[g[a][i]]/now*now);
	}
	dp1[a]=K*d;
//	printf("%d %d %d\n",a,dp1[a],dp2[a]);
}
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++)dp1[i]=b[i];
	for(int i=0;i<a-1;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	for(int i=0;i<a;i++)dp2[i]=1;
	dfs(0,-1);
	bool ok=true;
	long long ret=0;
	for(int i=0;i<a;i++){
		ret+=b[i];
		if(!~dp1[i])ok=false;
	}
	if(ok)ret-=dp1[0];
	printf("%I64d\n",ret);
}