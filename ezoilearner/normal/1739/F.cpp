#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2005;
int n,ans,vis[26],g[26][26],p[26][26],tot,dp[N*2][4096];char s[N];
pair<int,int>pre[N*2][4096];
struct Node{int son[13],val,fail;}tr[N*3];
inline void insert(vector<int>s,int v){
	int rt=0;
	for(auto x:s){
		if(!tr[rt].son[x])tr[rt].son[x]=++tot;
		rt=tr[rt].son[x];
	}
	tr[rt].val+=v;
}
inline void getFail(){
	queue<int>q;
	rep(i,1,12)if(tr[0].son[i])q.push(tr[0].son[i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		rep(i,1,12){
			int v=tr[u].son[i],Fail=tr[u].fail;
			if(!v){tr[u].son[i]=tr[Fail].son[i];continue;}
			tr[v].fail=tr[Fail].son[i];
			tr[v].val+=tr[tr[v].fail].val;q.push(v);
		}
	}
}
inline void solve(){
	rep(mask,0,4095)rep(i,0,tot)dp[i][mask]=-1e9;
	dp[0][0]=0;
	rep(mask,0,4095)rep(i,0,tot)if(dp[i][mask]>=0)
		rep(j,1,12)if(!(mask>>(j-1)&1)){
			int k=tr[i].son[j];
			if(dp[i][mask]+tr[k].val>dp[k][mask|(1<<j-1)])
				dp[k][mask|(1<<j-1)]=dp[i][mask]+tr[k].val,pre[k][mask|(1<<j-1)]={i,j};
		}
	int mx=0,mask=4095;
	rep(i,1,tot)if(dp[i][mask]>dp[mx][mask])mx=i;
	while(mask){
		int ch=pre[mx][mask].se;
		cout<<(char)('a'+ch-1);
		mx=pre[mx][mask].fi,mask^=(1<<ch-1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	rep(i,1,n){
		int v,len;
		cin>>v>>s+1,len=strlen(s+1);
		rep(j,1,12)vis[j]=0;
		rep(j,1,12)rep(k,1,12)g[j][k]=p[j][k]=0;
		rep(j,2,len)
			g[s[j]-'a'+1][s[j-1]-'a'+1]=g[s[j-1]-'a'+1][s[j]-'a'+1]=1;
		int ver=0,rt=0;
		queue<int>q;vector<int>vc;
		rep(j,1,12)if(g[j][j])goto NXT;
		rep(j,1,12){
			int fl=0;
			rep(k,1,12)fl+=g[j][k];
			if(fl>2)goto NXT;
			if(fl==1)rt=j,++ver;
		}
		if(!rt||ver!=2)goto NXT;
		q.push(rt),vis[rt]=1;
		while(!q.empty()){
			int now=q.front();vc.eb(now);q.pop();
			rep(j,1,12)if(g[now][j]&&!vis[j])vis[j]=1,q.push(j);
		}
		for(int j=1;j<vc.size();++j)
			p[vc[j]][vc[j-1]]=1;
		rep(j,2,len)
			if(!p[s[j]-'a'+1][s[j-1]-'a'+1]&&!p[s[j-1]-'a'+1][s[j]-'a'+1])
				goto NXT;
		insert(vc,v);
		reverse(vc.begin(),vc.end());
		insert(vc,v);
		NXT:;
	}
	getFail();
	solve();
	return 0;
}