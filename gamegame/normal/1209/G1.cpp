#include<bits/stdc++.h>
using namespace std;
const int mxa=200000;
#define fi first
#define se second
int n,m;
int a[200001];
int l[200001],r[200001],sz[200001];
int cnt[200001];
int mg[200001];
int mx[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		if(l[x]==0) l[x]=i;
		r[x]=i;
		sz[x]++;
	}
	for(int i=1; i<=mxa ;i++){
		if(!sz[i]) continue;
		mg[l[i]]++;mg[r[i]]--;
		mx[l[i]]=max(mx[l[i]],sz[i]);
	}
	int ans=n;
	for(int i=1; i<=n ;i++){
		int lp=i,rp=i;
		int cmx=mx[lp];
		while(mg[rp]){
			++rp;mg[rp]+=mg[rp-1];cmx=max(cmx,mx[rp]);
		}
		i=rp;
		ans-=cmx;
	}
	cout << ans << '\n';
}