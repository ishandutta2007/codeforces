#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,m,L[200005],R[200005],done[200005];
ll s[200005];
vector<int> g[200005];
queue<int> q;
void Make0(int x){
	s[x]=0;
	for(int i:g[x]){
		if(done[i])continue;
		int p=L[i],qq=R[i];
		if(!s[p]&&!s[qq])q.push(i),done[i]=1;
	}
}
void Solve(){
	set<int> nonz;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		s[i]-=x,s[i]+=s[i-1];
		if(s[i])nonz.insert(i);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&L[i],&R[i]);
		L[i]--;
		g[L[i]].push_back(i);
		g[R[i]].push_back(i);
		if(s[L[i]]==0&&s[R[i]]==0)q.push(i),done[i]=1;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int l=L[x],r=R[x];
		for(auto it=nonz.lower_bound(l);it!=nonz.end();it=nonz.lower_bound(l)){
			if((*it)>r)break;
			int u=*it;
			Make0(u);
			nonz.erase(u);
		}
	}
	bool ok=1;
	for(int i=1;i<=n;i++)if(s[i])ok=0;
	if(!ok)puts("No");
	else puts("Yes");
	for(int i=0;i<=n;i++)s[i]=0,g[i].clear();
	for(int i=0;i<=m;i++)done[i]=L[i]=R[i]=0;
	while(!q.empty())q.pop();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}