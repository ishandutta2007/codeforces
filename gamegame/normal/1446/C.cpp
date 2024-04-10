#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e5+1;
int n,m;
int a[N];
const int ts=1e7+1;
int ch[ts][2];
int f[ts],dp[ts];
int sz=1;
void ins(int x){
	int id=1;
	for(int i=29; i>=0 ;i--){
		int cur=(x>>i)&1;
		if(ch[id][cur]==0) ch[id][cur]=++sz;
		id=ch[id][cur];
	}
	f[id]++;
}
void dfs(int id){
	int lc=0,rc=0;
	if(ch[id][0]!=0){
		dfs(ch[id][0]);
		lc=dp[ch[id][0]];
	}
	if(ch[id][1]!=0){
		dfs(ch[id][1]);
		rc=dp[ch[id][1]];
	}
	dp[id]=max(lc+min(rc,1),min(lc,1)+rc);
	if(f[id]!=0) dp[id]=1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		ins(a[i]);
	}
	dfs(1);
	cout << n-dp[1] << '\n';
}