#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1025;
bool v[maxn];
vector<int> ans;
vector<int> G[maxn];
int n,d,a[maxn],cnt,to[maxn];
char s[11];
bool cmp(int u,int v){
	return __builtin_popcount(u)>__builtin_popcount(v);
}

bool dfs(int u){
	for (auto i:G[u]){
	    if (!v[i]){
	    	v[i]=true;
	    	if (to[i]==-1||dfs(to[i])){
	    		to[i]=u;
	    		return 1;
	    	}
	    }
	}
    return 0;
}
void solve(int x){
    if (!to[x]){
		int mask=a[x];
		for (int i=0;i<d;i++) if (mask&(1<<i)) printf("%d ",i);
    } else {
		solve(to[x]);
		int mask=a[x]^a[to[x]];
		for (int i=0;i<d;i++) if (mask&(1<<i)) printf("%d ",i);
    }
}
int main(){
	cin >> d >> n;
	for (int i=1;i<=n;i++){
        cin >> s;
        for (int j=0;j<d;j++){
			if (s[j]=='1') a[i]|=1<<j;
        }
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	for (int j=1;j<i;j++){
		if ((a[i]&a[j])==a[i]) G[i].pb(j);
	}
	memset(to,-1,sizeof(to));
	for (int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		if (!dfs(i)) {
			ans.pb(i);
			cnt+=__builtin_popcount(a[i])+1;
		}
	}
	printf("%d\n",cnt-1);
	for (int i=0;i<ans.size();i++){
        if (i) printf("R ");
        solve(ans[i]);
	}
	puts("");
	return 0;
}