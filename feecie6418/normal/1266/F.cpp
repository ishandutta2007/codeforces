#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pr;
struct Thing{
	int w,fr;
}a[500005];
int n,h[500005],ans[1000005],f[500005],t[500005],cnt[500005];
vector<int> g[500005];
multiset<int> tmp[500005];
void dfs1(int x,int fa){
	for(int y:g[x]){
		if(y==fa)continue;
		dfs1(y,x);
		f[x]=max(f[x],f[y]+1);
	}
}
void dfs2(int x,int fa){
	multiset<int> s;
	for(int y:g[x])if(y!=fa)s.insert(f[y]);
	for(int y:g[x]){
		if(y==fa)continue;
		s.erase(s.find(f[y]));
		if(s.size())h[y]=max(h[y],*--s.end()+2);
		h[y]=max(h[y],h[x]+1);
		dfs2(y,x);
		s.insert(f[y]);
	}
	int ts=0;
	for(int y:g[x])if(y^fa)t[++ts]=f[y]+1;
	if(fa)t[++ts]=h[x];
	sort(t+1,t+ts+1);
	for(int i=1;i<=ts;i++){
		ans[2*t[i]-1]=max(ans[2*t[i]-1],ts-i+1);
		if(i>1&&t[i]>t[i-1])ans[2*t[i-1]+1]=max(ans[2*t[i-1]+1],ts-i+2);
		ans[2*t[i]]=max(ans[2*t[i]],ts-i+1);
	}
	ts=0;
	for(int y:g[x])if(y^fa)a[++ts]={f[y]+1,-x},tmp[0].insert(f[y]+1);
	if(fa)a[++ts]={h[x],-x};
	for(int y:g[x]){
		if(y==fa)continue;
		for(int z:g[y]){
			if(z==x)continue;
			a[++ts]={f[z]+1,y};
		}
	}
	int mx=-1e9;
	sort(a+1,a+ts+1,[](Thing x,Thing y){return x.w!=y.w?x.w>y.w:x.fr<y.fr;});
	for(int i=1;i<=ts;i++){
		int y=a[i].fr;
		if(y>0){
			tmp[cnt[y]].erase(tmp[cnt[y]].find(f[y]+1));
			cnt[y]++;
			tmp[cnt[y]].insert(f[y]+1);
		}
		else cnt[x]++;
		if(y>0&&cnt[y]>mx)mx=cnt[y];
		bool ok=0;
		if(mx>=0&&tmp[mx].size()&&*tmp[mx].begin()>=a[i].w)ok=1;
		ans[2*a[i].w]=max(ans[2*a[i].w],cnt[x]+mx-ok);
	}
	cnt[x]=0;
	for(int y:g[x])if(y^fa)tmp[cnt[y]].clear(),cnt[y]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=2,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)ans[1]=max(ans[1],(int)g[i].size()+1);
	dfs1(1,0),dfs2(1,0);
	for(int i=n;i;i--)ans[i]=max(ans[i],max(1,ans[i+2]));
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}