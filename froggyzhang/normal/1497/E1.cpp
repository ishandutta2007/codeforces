#include<bits/stdc++.h>
using namespace std;
#define N 200002
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,a[N],dp[N][21];
bool ntp[N];
int p[N>>2],pn;
void init(int n){
	ntp[1]=true;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
}
map<int,int> las;
int lg[N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		for(int j=1;j<=pn&&p[j]*p[j]<=a[i];++j){
			while(a[i]%(p[j]*p[j])==0)a[i]/=p[j]*p[j];
		}
	}
	static vector<int> vec;
	vec.clear();
	las.clear();
	dp[0][0]=0;
	for(int i=1;i<=m;++i)dp[0][i]=n+1;
	vec.push_back(0);
	for(int i=1;i<=n;++i){
		if(las.count(a[i])){
			vec.insert(lower_bound(vec.begin(),vec.end(),las[a[i]]),las[a[i]]);
		}
		las[a[i]]=i;
		for(int j=0;j<=m;++j){
			dp[i][j]=n+1;
			for(int k=0;k<=min(j,(int)vec.size()-1);++k){
				dp[i][j]=min(dp[i][j],dp[vec[(int)vec.size()-k-1]][j-k]+1);
			}
		}
	}
	int ans=n+1;
	for(int i=0;i<=m;++i)ans=min(ans,dp[n][i]);
	printf("%d\n",ans);
}
int main(){
	init(40000);
	for(int i=2;i<=200001;++i)lg[i]=lg[i>>1]+1;
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}