#include<bits/stdc++.h>
using namespace std;
struct Trie{
	int cnt,root,tr[13000005][2];
	Trie(void):cnt(1),root(1){}
	void Insert(int p){
		int now=root,m[34]={0};
		while(p)m[++m[0]]=p%2,p/=2;
		for(int i=31;i>=1;i--){
			if(!tr[now][m[i]])tr[now][m[i]]=++cnt;
			now=tr[now][m[i]];
		}
	}
	int GetMn(int p){
		if(cnt==1)return 2147483647;
		int now=root,m[34]={0},ret=0;
		while(p)m[++m[0]]=p%2,p/=2;
		for(int i=31;i>=1;i--){
			if(tr[now][m[i]])now=tr[now][m[i]];
			else {
				ret+=(1<<i-1);
				now=tr[now][1-m[i]];
			}
		}
		return ret;
	}
	void Clear(){
		for(int i=1;i<=cnt;i++)tr[i][0]=tr[i][1]=0;
		root=cnt=1;
	}
}trie;
int n;
long long ans;
vector<int> a;
void dfs(vector<int> a,int d){
	if(!a.size()||d<0)return ;
	vector<int> a1,a2;
	for(int i:a)if(i&(1<<d))a1.push_back(i);else a2.push_back(i);
	if(a1.size()&&a2.size()){
		trie.Clear();
		for(int i:a1)trie.Insert(i);
		int o=2147483647;
		for(int i:a2)o=min(o,trie.GetMn(i));
		ans+=o;
	}
	dfs(a1,d-1),dfs(a2,d-1);
}
int main(){
	scanf("%d",&n),a.resize(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	dfs(a,30);
	printf("%lld\n",ans);
	return 0;
}