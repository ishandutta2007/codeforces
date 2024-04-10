#include<bits/stdc++.h>
using namespace std;
#define N 18
typedef long long ll;
typedef vector<ll> poly;
char s[20];
int n,a[N][N];
ll dp[1<<N][N];
poly ans,g[N+1];
void FWT_or(poly &f,int n){
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				f[i+len]+=f[i];	
			}
		}	
	}
}
void Solve(vector<int> fen,const poly &A){
	ll tmp=0;
	int all=(1<<n)-1;
	for(int i=0;i<(1<<n);++i){
		tmp+=(__builtin_popcount(i^all)&1?-1:1)*A[i];
	}
	do{
		int st=all,sum=0;
		for(auto x:fen){
			sum+=x;
			st^=1<<sum-1;
		}
		ans[st]=tmp;
	}while(prev_permutation(fen.begin(),fen.end()));
}
void dfs(int m,vector<int> &fen,const poly &A){
	if(!m){
		Solve(fen,A);
		return;
	}
	int lim=m;
	if(!fen.empty())lim=min(lim,fen.back());
	for(int i=1;i<=lim;++i){
		fen.push_back(i);
		poly B=A;
		for(int s=0;s<(1<<n);++s){
			B[s]*=g[i][s];
		}
		dfs(m-i,fen,B);
		fen.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		for(int j=0;j<n;++j){
			a[i][j]=s[j]-'0';
		}
		dp[1<<i][i]=1;
	}
	ans.resize(1<<n-1);
	for(int s=1;s<(1<<n);++s){
		for(int i=0;i<n;++i){
			if(dp[s][i]){
				for(int j=0;j<n;++j){
					if(a[i][j]&&!(s>>j&1)){
						dp[s|(1<<j)][j]+=dp[s][i];
					}	
				}	
			}	
		}	
	}
	for(int i=1;i<=n;++i){
		g[i].resize(1<<n);	
	}
	for(int s=1;s<(1<<n);++s){
		int cnt=__builtin_popcount(s);
		for(int i=0;i<n;++i){
			g[cnt][s]+=dp[s][i];	
		}
	}
	for(int i=1;i<=n;++i){
		FWT_or(g[i],1<<n);
	}
	vector<int> tmp;
	poly jb(1<<n,1);
	dfs(n,tmp,jb);
	for(int j=0;j<n-1;++j){
		for(int i=0;i<(1<<n-1);++i){
			if(i>>j&1)ans[i^(1<<j)]-=ans[i];
		}
	}
	for(int i=0;i<(1<<n-1);++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}