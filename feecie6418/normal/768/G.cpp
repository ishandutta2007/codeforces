#include<bits/stdc++.h>
#define L(x) dfn[x]
#define R(x) dfn[x]+size[x]-1
using namespace std;
typedef long long ll;
int n,size[100005],rt,ans[100005],dfn[100005],id[100005],son[100005],sign;
vector<int> g[100005];
multiset<int> anc,oth,sons;
void dfs(int x){
	size[x]=1,dfn[x]=++sign,id[sign]=x;
	for(int y:g[x]){
		dfs(y),size[x]+=size[y];
		if(size[y]>size[son[x]])son[x]=y;
	}
	oth.insert(size[x]);
}
void dfs2(int x){
	anc.insert(size[x]),oth.erase(oth.find(size[x]));
	for(int y:g[x]){
		if(y==son[x])continue;
		dfs2(y);
		for(int i=L(y);i<=R(y);i++)sons.erase(sons.find(size[id[i]])),oth.insert(size[id[i]]);
	}
	if(son[x])dfs2(son[x]);
	for(int y:g[x]){
		if(y==son[x])continue;
		for(int i=L(y);i<=R(y);i++)oth.erase(oth.find(size[id[i]]));
	}
	anc.erase(anc.find(size[x])),ans[x]=1e9;
	assert(sons.size()==size[son[x]]);
	//cout<<x<<' '<<oth.size()<<endl;
	//for(int i:oth)cout<<i<<' ';
	//puts("");
	assert(oth.size()==n-anc.size()-size[x]);
	vector<int> v;
	for(int y:g[x])v.push_back(size[y]);
	if(size[x]!=n)v.push_back(n-size[x]);
	sort(v.begin(),v.end()),ans[x]=v.back();
	int pre=0,w=(v.back()-v.front())/2;
	if(v.back()==n-size[x]){
		if(anc.lower_bound(w+size[x])!=anc.begin())pre=max(pre,(*--anc.lower_bound(w+size[x]))-size[x]);
		if(oth.lower_bound(w)!=oth.begin())pre=max(pre,*--oth.lower_bound(w));
	}
	else {
		if(sons.lower_bound(w)!=sons.begin())pre=max(pre,*--sons.lower_bound(w));
	}
	if(pre&&v.size()>1)ans[x]=min(ans[x],max({v.back()-pre,v.front()+pre,v[v.size()-2]}));
	int suf=1e9;
	if(v.back()==n-size[x]){
		if(anc.lower_bound(w+size[x])!=anc.end())suf=min(suf,(*anc.lower_bound(w+size[x]))-size[x]);
		if(oth.lower_bound(w)!=oth.end())suf=min(suf,*oth.lower_bound(w));
	}
	else {
		if(sons.lower_bound(w)!=sons.end())suf=min(suf,*sons.lower_bound(w));
	}
	if(suf!=1e9&&v.size()>1)ans[x]=min(ans[x],max({v.back()-suf,v.front()+suf,v[v.size()-2]}));
	sons.insert(size[x]);
	for(int y:g[x]){
		if(y==son[x])continue;
		for(int i=L(y);i<=R(y);i++)sons.insert(size[id[i]]);
	}
}
int main(){
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(!x)rt=y;
		else g[x].push_back(y);
	}
	dfs(rt),dfs2(rt);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}