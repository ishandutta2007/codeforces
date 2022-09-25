#include<bits/stdc++.h>
using namespace std;
#define N 14
typedef long long ll;
typedef pair<int,int> pii;
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
int n,mp[N][N],m,all;
vector<pii> dp[1<<14];
vector<int> cir[1<<14],g[1<<14][14][14];
void Merge(vector<pii> &A,vector<pii> &B,vector<pii> &C){
	if(B.size()&&C.size()&&(A.empty()||A.size()>B.size()+C.size())){
		A=B;
		A.insert(A.end(),C.begin(),C.end());
	}
}
int main(){
	n=read(),m=read();
	for(int i=0;i<m;++i){
		int u=read()-1,v=read()-1;
		mp[u][v]=mp[v][u]=1;
	}
	for(int i=0;i<n;++i){
		g[1<<i][i][i].push_back(i);
	}
	assert(__builtin_ctz(1)==0);
	for(int s=0;s<(1<<n);++s){
		for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				if(g[s][k][i].empty())continue;
				for(int j=0;j<n;++j){
					if(!mp[i][j])continue;
					if((int)g[s][k][i].size()>=2&&j==g[s][k][i][(int)g[s][k][i].size()-2])continue;
					if(s>>j&1){
						if(j==k&&__builtin_popcount(s)>2){
							cir[s]=g[s][k][i];
						}
					}
					else{
						g[s|(1<<j)][k][j]=g[s][k][i];
						g[s|(1<<j)][k][j].push_back(j);
					}
				}	
			}
		}
	}
	for(int s=0;s<(1<<n);++s){
		for(int k=0;k<(int)cir[s].size();++k){
			dp[s].emplace_back(cir[s][k],cir[s][(k+1)%cir[s].size()]);
		}
	}
	all=(1<<n)-1;
	for(int s=1;s<=all;++s){
		for(int t=s;t;t=(t-1)&s){
			if((int)dp[s].size()==__builtin_popcount(s))break;
			for(int i=0;i<n;++i){
				if(t>>i&1){
					int z=(s^t)|(1<<i);
					vector<pii> tmp;
					for(int k=0;k<(int)cir[t].size();++k){
						tmp.emplace_back(cir[t][k],cir[t][(k+1)%cir[t].size()]);
					}
					Merge(dp[s],dp[z],tmp);
				}	
			}
			for(int i=0;i<n;++i){
				for(int j=i+1;j<n;++j){
					if(t>>i&1&&t>>j&1){
						int z=(s^t)|(1<<i)|(1<<j);
						vector<pii> tmp;
						for(int k=0;k<(int)g[t][i][j].size()-1;++k){
							tmp.emplace_back(g[t][i][j][k],g[t][i][j][k+1]);
						}
						Merge(dp[s],dp[z],tmp);
					}		
				}
			}
		}		
	}
	printf("%d\n",(int)dp[all].size());
	for(auto [x,y]:dp[all])printf("%d %d\n",x+1,y+1);
	return 0;
}