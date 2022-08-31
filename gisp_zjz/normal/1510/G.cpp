#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e3+10;
int n,_,dep[maxn],pre[maxn],k,pos,a[maxn];
vector<int> G[maxn],ans;
bool ban[maxn];
void dfs(int u){
	for (auto v:G[u]){
		if (k==0||ban[v]) continue;
		k--; ans.pb(v); dfs(v); ans.pb(u);
	}
}
int main(){
	cin >> _;
	while (_--){
		cin >> n >> k; --k;
		ans.clear(); pos=1;
		memset(ban,0,sizeof(ban));
		for (int i=1;i<=n;i++) G[i].clear();
		for (int i=2;i<=n;i++){
			int x; cin >> x;
            G[x].pb(i); pre[i]=x;
            dep[i]=dep[x]+1;
            if (dep[pos]<dep[i]) pos=i;
		}
		int h=dep[pos];
        if (h>=k){
            while (dep[pos]>k) pos=pre[pos];
            while (pos) ans.pb(pos),pos=pre[pos];
            reverse(ans.begin(),ans.end());
        } else {
            k-=h;
            for (int i=h;i>=0;i--) ban[pos]=1,a[i]=pos,pos=pre[pos];
            for (int i=0;i<=h;i++) {
				ans.pb(a[i]);
				dfs(a[i]);
            }
        }
		printf("%d\n",(int)ans.size()-1);
		for (auto x:ans) printf("%d ",x);puts("");
	}
	return 0;
}