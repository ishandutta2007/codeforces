#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int M=1010;
const ll inf=1e18;
const int mo=998244353;
char s[N];int p[14][M],f[M],t[M];
ll dp[M][1<<14],w[M],a[M];
int main(){int n,m,tot=0;
	scanf("%d",&n);
	rep(i,1,n){int W;
		scanf("%s%d",s+1,&W);
		m=strlen(s+1);int x=0;
		rep(j,1,m){
			int c=s[j]-'a';
			if(!p[c][x])p[c][x]=++tot;
			x=p[c][x];
		}
		w[x]+=W;
	}
	queue<int>q;q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		rep(i,0,13)if(p[i][x]){
			f[p[i][x]]=x?p[i][f[x]]:0;
			w[p[i][x]]+=w[f[p[i][x]]];
			q.push(p[i][x]);
		}else p[i][x]=p[i][f[x]];
	}
	scanf("%s",s+1);m=strlen(s+1);
	rep(j,0,tot)rep(k,0,(1<<14)-1)dp[j][k]=-inf;
	dp[0][0]=0;
	rep(j,0,tot)t[j]=j;
	rep(i,1,m)if(s[i]=='?'){
		dep(k,(1<<14)-1,0)rep(j,0,tot)if(dp[j][k]!=-inf){
			rep(l,0,13)if(!((1<<l)&k)){
				int jj=p[l][t[j]],kk=k^(1<<l);
				dp[jj][kk]=max(dp[jj][kk],dp[j][k]+a[j]+w[jj]);
			}
			dp[j][k]=-inf;
		}
		rep(j,0,tot)t[j]=j,a[j]=0;
	}else rep(j,0,tot){
		t[j]=p[s[i]-'a'][t[j]];
		a[j]+=w[t[j]];
	}ll ans=-inf;
	rep(j,0,tot)rep(k,0,(1<<14)-1)ans=max(ans,dp[j][k]+a[j]);
	printf("%lld\n",ans);
}