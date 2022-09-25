#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n=20;
int len,p[n],G[n][n],g[1<<n],dp[1<<n];
string s,t;
class Union_Set{
	int f[n];
public:
	void init(int n){
		for(int i=0;i<n;++i)f[i]=i;
	}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	inline int Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return 0;
		f[fy]=fx;
		return 1;
	}
}S;
void Solve(){
	cin>>len>>s>>t;
	for(int i=0;i<n;++i)p[i]=0;
	memset(G,0,sizeof(G));
	S.init(n);
	int tmp=0;
	for(int i=0;i<len;++i){
		int u=s[i]-'a';
		int v=t[i]-'a';
		G[u][v]=1;
		tmp+=S.Merge(u,v);
	}
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(G[i][j])p[i]|=1<<j;	
		}
	}
	memset(dp,0x3f,sizeof(dp));
	memset(g,0,sizeof(g));
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<n;++j){
			if(i>>j&1)g[i]|=p[j];
		}
	}
	dp[0]=0;
	#define update(x,y) x=min(x,y)
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<n;++j){
			if(!(i>>j&1)){
				update(dp[i|(1<<j)],dp[i]+(g[i]>>j&1));
			}	
		}	
	}
	cout<<tmp+dp[(1<<n)-1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}