#include<bits/stdc++.h>
using namespace std;
struct E{
	int to,id;
};
int m,d[10005],v[10005],us[10005],sum[6],s,su=0,a[6],W[100005];
vector<E> g[10005];
vector<int> ans;
void dfss(int x){
	v[x]=1;
	if(d[x]&1)s++;
	for(E i:g[x]){
		int y=i.to;
		if(v[y])continue;
		dfss(y);
	}
}
void dfs(int x){
	us[x]=1;
	for(E i:g[x]){
		int y=i.to;
		if(v[i.id])continue;
		v[i.id]=1,dfs(y),ans.push_back(i.id);
	}
}
void Find(int x,int &I){
	W[x]=1;
	if(d[x]&1)I=x;
	for(E i:g[x]){
		int y=i.to;
		if(W[y])continue;
		Find(y,I);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>m;
	if(m==1)return puts("-1"),0;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y,d[x]++,d[y]++;
		g[x].push_back({y,i}),g[y].push_back({x,i});
	}
	for(int i=1;i<=10000;i++)if(d[i]%2)++su;
	if(su>4)return puts("-1"),0;
	for(int i=1;i<=10000;i++){
		if(!g[i].size()||v[i])continue;
		s=0,dfss(i),sum[s]++;
	}
	if(sum[4]&&sum[0])return puts("-1"),0;
	if(sum[0]>2)return puts("-1"),0;
	if(sum[4]){
		for(int i=1;i<=10000;i++)if(d[i]%2)a[++a[0]]=i;
		g[a[1]].push_back({a[2],m+1}),g[a[2]].push_back({a[1],m+1});
		d[a[1]]++,d[a[2]]++;
		memset(v,0,sizeof(v));
		for(int i=1;i<=10000;i++){
			if(d[i]&1){
				dfs(i);
				break;
			}
		}
		int pos=0;
		for(int i=0;i<ans.size();i++)if(ans[i]==m+1)pos=i;
		cout<<pos<<endl;
		for(int i=0;i<pos;i++)cout<<ans[i]<<' ';
		cout<<endl<<ans.size()-pos-1<<endl;
		for(int i=pos+1;i<ans.size();i++)cout<<ans[i]<<' ';
		return 0;
	}
	if(sum[0]+sum[2]==1){
		memset(v,0,sizeof(v));
		for(int i=1;i<=10000;i++){
			if(g[i].size()&&!us[i]){
				ans.clear();
				int p=i;
				Find(i,p),dfs(p),cout<<ans.size()-1<<endl;
				for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<' ';
				cout<<endl<<1<<endl<<ans.back();
			}
		}
		return 0;
	}
	memset(v,0,sizeof(v));
	for(int i=1;i<=10000;i++){
		if(g[i].size()&&!us[i]){
			ans.clear();
			int p=i;
			Find(i,p),dfs(p),cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
			cout<<endl;
		}
	}
}