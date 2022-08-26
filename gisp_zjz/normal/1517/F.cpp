#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=305;
const int M=998244353;
int n,ans,tot,k,p2[maxn],sz[maxn];
vector<int> dp[maxn];
vector<int> G[maxn];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
vi comb(vi &a,vi &b){
	vi sa=a,sb=b;
	for (int i=1;i<=k*2;i++){
		add(sa[i],sa[i-1]);
		add(sb[i],sb[i-1]);
	}
	vi res; res.resize(k*2+1);
    for (int i=0;i<k;i++){
        res[i]=1ll*a[i]*sb[k*2-1-i]%M;
        add(res[i],1ll*b[i]*sa[k*2-1-i]%M);
        if (i) {
			sub(res[i],1ll*a[i]*sb[i-1]%M);
			sub(res[i],1ll*b[i]*sa[i-1]%M);
        }
        sub(res[i],1ll*a[i]*b[i]%M);
    }
    for (int i=k;i<=k*2;i++){
        res[i]=1ll*a[i]*sb[i]%M;
        add(res[i],1ll*b[i]*sa[i]%M);
        if (i<k*2){
			sub(res[i],1ll*a[i]*sb[k*2-1-i]%M);
			sub(res[i],1ll*b[i]*sa[k*2-1-i]%M);
        }
        sub(res[i],1ll*a[i]*b[i]%M);
    }
    return res;
}
void dfs(int u,int fa){
	dp[u][k]=1;
	sz[u]=1;
	vi tmp;
    for (auto v:G[u]){
		if (v==fa) continue;
		dfs(v,u); sz[u]+=sz[v];
		tmp=dp[u];
		dp[u]=comb(tmp,dp[v]);
    }
    int sum=0;
    for (int i=0;i<=k*2;i++) add(sum,dp[u][i]);
    for (int i=k*2;i;i--) dp[u][i]=dp[u][i-1];
    dp[u][0]=sum;
}
int main(){
	cin >> n;
	for (int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		//u=i; v=i+1;
		G[u].pb(v); G[v].pb(u);
	}
	p2[0]=1; for (int i=1;i<=n;i++) p2[i]=p2[i-1]*2%M;
	for (k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			dp[i].resize(k*2+1);
			for (int j=0;j<dp[i].size();j++) dp[i][j]=0;
		}
        dfs(1,0);
        int res=p2[n];
        for (int j=0;j<=k;j++) sub(res,dp[1][j]);
        add(ans,res);
	}
    sub(ans,1);
    for (int i=1;i<=n;i++) ans=1ll*ans*(M+1)/2%M;
    cout << ans << endl;
    return 0;
}