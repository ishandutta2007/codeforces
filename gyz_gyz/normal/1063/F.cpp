#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,tot,ans,rk[N],sa[N],dp[N],w[N],lcp[N][20];
bool df[N];char s[N];vector<int>v1[N],v2[N];
void f(int x,int y,int z,int L,int R){
	if(L==R){w[x]=z;return;}int m=(L+R)/2;
	if(y<=m)f(x*2,y,z,L,m);else f(x*2+1,y,z,m+1,R);
	w[x]=max(w[x*2],w[x*2+1]);
}
int q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return w[x];int m=(L+R)/2;
	if(r<=m)return q(x*2,l,r,L,m);
	if(l>m)return q(x*2+1,l,r,m+1,R);
	return max(q(x*2,l,m,L,m),q(x*2+1,m+1,r,m+1,R));
}
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	rep(i,1,n)v1[s[i]-'a'+1].pb(i);
	rep(i,1,26)if(!v1[i].empty()){tot++;
		for(auto j:v1[i])rk[j]=tot;
	}
	rep(i,0,18){tot=0;
		rep(j,0,n){
			v1[j].clear();v2[j].clear();df[j]=0;
		}
		rep(j,1,n)v1[rk[j+(1<<i)]].pb(j);
		rep(j,0,n)for(auto k:v1[j]){
			if(v2[rk[k]].empty()||rk[*(--v2[rk[k]].end())+(1<<i)]!=rk[k+(1<<i)])df[k]=1;
			v2[rk[k]].pb(k);
		}
		rep(j,0,n)for(auto k:v2[j]){
			if(df[k])tot++;rk[k]=tot;
		}
	}
	rep(i,1,n)sa[rk[i]]=i;
	rep(i,1,n){
		lcp[rk[i]][0]=max(lcp[rk[i-1]][0]-1,0);
		while(s[i+lcp[rk[i]][0]]==s[sa[rk[i]-1]+lcp[rk[i]][0]])lcp[rk[i]][0]++;
	}
	rep(j,1,19)rep(i,1,n)lcp[i][j]=min(lcp[i][j-1],lcp[i+(1<<(j-1))][j-1]);
	dep(i,n,1){
		dp[i]=dp[i+1]+1;
		while(dp[i]>1){
			int l=rk[i],r=rk[i]+1;
			dep(j,19,0){
				if(l>=1<<j&&lcp[l+1-(1<<j)][j]>=dp[i]-1)l-=1<<j;
				if(lcp[r][j]>=dp[i]-1)r+=1<<j;
			}
			if(q(1,l,r-1,1,n)+1>=dp[i])break;
			l=rk[i+1];r=rk[i+1]+1;
			dep(j,19,0){
				if(l>=1<<j&&lcp[l+1-(1<<j)][j]>=dp[i]-1)l-=1<<j;
				if(lcp[r][j]>=dp[i]-1)r+=1<<j;
			}
			if(q(1,l,r-1,1,n)+1>=dp[i])break;
			dp[i]--;f(1,rk[i+dp[i]],dp[i+dp[i]],1,n);
		}
		if(dp[i]>ans)ans=dp[i];
	}
	printf("%d\n",ans);
}