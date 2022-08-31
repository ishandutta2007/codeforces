#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define fi first
#define se second
int n,s,m,k;
int a[1501];
pair<int,int>b[1501];
pair<int,int>seg[1501];
int sz;
int l[1501],r[1501];
vector<int>en[1501];
int p[1501];
int dp[1501][1501];
int dp2[1501][1501];
int lol[1501][1501];
int qst[1501],qen[1501];
int cnt(int mid){//count numbers < mid
	for(int i=1; i<=n ;i++) p[i]=p[i-1]+(a[i]<mid);
	int ans=0;
	for(int i=0; i<=m ;i++){
		dp[0][i]=dp2[0][i]=-1e9;
		qst[i]=1,qen[i]=0;
	}
	dp[0][0]=0;
	dp2[0][0]=0;
	int cur=1;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<=m ;j++){
			dp2[i][j]=dp2[i-1][j];
			dp[i][j]=-1e9;
		}
		if(cur<=sz && r[cur]==i){
			int last=0;
			while(r[last+1]<l[cur]) last++;
			for(int j=m; j>=1 ;j--){
				while(qst[j-1]<=qen[j-1] && lol[j-1][qst[j-1]]<l[cur]) qst[j-1]++;
				if(qst[j-1]<=qen[j-1]) dp[i][j]=max(dp[i][j],dp[lol[j-1][qst[j-1]]][j-1]);
				dp[i][j]=max(dp[i][j],dp2[r[last]][j-1]-p[l[cur]-1]);
				while(qst[j]<=qen[j] && dp[lol[j][qen[j]]][j]<=dp[i][j]) qen[j]--;
				lol[j][++qen[j]]=i;
				dp2[i][j]=max(dp2[i][j],dp[i][j]+p[i]);
			}
			cur++;
		}
	}
	return dp2[n][min(sz,m)];
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s >> m >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]={a[i],i};
	}
	sort(b+1,b+n+1);
	for(int i=1; i<=n ;i++) a[b[i].se]=i;
	for(int i=1; i<=s ;i++){
		cin >> seg[i].se >> seg[i].fi;
		seg[i].se=-seg[i].se;
	}
	sort(seg+1,seg+s+1);
	for(int i=1; i<=s ;i++){
		seg[i].se=-seg[i].se;
		while(sz>0 && seg[i].se<=l[sz]) sz--;
		l[++sz]=seg[i].se;r[sz]=seg[i].fi;
	}
	int l=1,r=n+1;
	while(l!=r){
		int mid=(l+r+1)/2;
		if(cnt(mid)>=k) r=mid-1;
		else l=mid;
	}
	if(l==n+1) cout << -1 << endl;
	else cout << b[l].fi << endl;
}