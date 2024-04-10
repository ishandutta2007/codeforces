#include<bits/stdc++.h>
using namespace std;
#define N 153050
typedef long long ll;
int n,tot;
struct Data{
	array<int,10> p;	
	int c,z;
	Data(){for(int i=0;i<10;++i)p[i]=0;c=0;}
	friend bool operator < (const Data &a,const Data &b){
		return a.p<b.p;
	}
}a[N];
string s[10];
vector<int> p[10][52];
int id[52][1<<10],dp[N],pre[N];
int Get(char c){
	if(c>='a'&&c<='z')return c-'a';
	return c-'A'+26;	
}
void dfs(int u){
	if(!u)return;
	dfs(pre[u]);
	if(dp[u]>dp[pre[u]]){
		cout<<(char)(a[u].c<26?a[u].c+'a':a[u].c-26+'A');	
	}
}
void Solve(){
	cin>>n;
	for(int j=0;j<n;++j){
		for(int i=0;i<52;++i){
			p[j][i].clear();
		}
	}
	for(int i=0;i<n;++i){
		cin>>s[i];
		for(int j=0;j<(int)s[i].size();++j){
			p[i][Get(s[i][j])].push_back(j);
		}
	}
	tot=0;
	for(int i=0;i<52;++i){
		for(int k=0;k<(1<<n);++k){
			Data tmp;
			tmp.c=i,tmp.z=k;
			bool ok=true;
			for(int j=0;j<n;++j){
				int t=k>>j&1;
				if(t>=p[j][i].size()){
					ok=false;
					break;
				}
				tmp.p[j]=p[j][i][t];
			}
			if(ok)a[++tot]=tmp;
		}
	}
	memset(dp,0,sizeof(dp));
	memset(id,0,sizeof(id));
	memset(pre,0,sizeof(pre));
	sort(a+1,a+tot+1);
	for(int i=1;i<=tot;++i){
		id[a[i].c][a[i].z]=i;
	}
	for(int i=1;i<=tot;++i){
		int c=a[i].c;
		dp[i]=1;
		for(int j=0;j<n;++j){
			if(a[i].z>>j&1){
				if(dp[id[c][a[i].z^(1<<j)]]>dp[i]){
					dp[i]=dp[id[c][a[i].z^(1<<j)]];
					pre[i]=id[c][a[i].z^(1<<j)];
				}
			}	
		}
		for(int k=0;k<52;++k){
			int g=0;
			bool ok=true;
			for(int j=0;j<n;++j){
				if(p[j][k].empty()||a[i].p[j]<=p[j][k][0]){
					ok=false;break;
				}
				if(p[j][k].size()>1&&a[i].p[j]>p[j][k][1]){
					g|=1<<j;
				}	
			}
			if(ok){
				if(dp[id[k][g]]+1>dp[i]){
					dp[i]=dp[id[k][g]]+1;
					pre[i]=id[k][g];		
				}
			}
		}
	}
	int ans=*max_element(dp+1,dp+tot+1);
	cout<<ans<<'\n';
	for(int i=1;i<=tot;++i){
		if(dp[i]==ans){
			dfs(i);
			break;	
		}
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}