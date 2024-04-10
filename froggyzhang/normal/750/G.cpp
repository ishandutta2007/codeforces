#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
int C[3][3];
inline ll get_dis(ll u,ll v){
	if(u<v)swap(u,v);
	ll Len=0;
	while(__lg(u)>__lg(v))Len+=u,u>>=1;
	while(u^v)Len+=u,Len+=v,u>>=1,v>>=1;
	Len+=u;
	return Len;	
}
ll calc(ll S,int t1,int t2,int Z){
	static ll dp[N][N<<1][2];
	static int g[N],m;
	S>>=1;
	m=0;
	while(S){
		g[++m]=S&1;
		S>>=1;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<m;++i){
		for(int j=0;j<=t1+t2;++j){
			for(int c=0;c<=1;++c){
				ll w=dp[i][j][c];
				if(!w)continue;
				int zyk=(i+1<=t1)+(i+1<=t2);
				for(int k=0;k<=zyk;++k){
					int x=(c+k)&1,y=(c+k)>>1;
					if(x^g[i+1])continue;
					dp[i+1][j+k][y]+=w*C[zyk][k];
				}
			}
		}
	}
	return dp[m][Z][0];
}
void Solve(){
	ll S;
	cin>>S;
	ll ans=0;
	for(int h1=0;h1<=53;++h1){
		for(int h2=0;h2<=53;++h2){
			ll p=(1LL<<h1+1)+(1LL<<h2+1)-3;
			if(S<(1LL<<h2)-1)break;
			ll rt=(S-((1LL<<h2)-1))/p;
			if(!rt)break;
			ll qwq=(S-((1LL<<h2)-1)-rt*p);
			int t1=max(0,h1-1),t2=max(0,h2-1);
			for(int i=0;i<=t1+t2;++i,++qwq){
				if(qwq&1)continue;
				ans+=calc(qwq,t1,t2,i);
			} 
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	C[0][0]=C[1][0]=C[2][0]=C[2][2]=C[1][1]=1;
	C[2][1]=2;
	Solve();
	return 0;
}