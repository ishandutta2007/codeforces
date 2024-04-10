#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],len[100005],m;
vector<int> g[100005];
void dfs(int x){
	len[x]=1;
	for(int y:g[x])dfs(y),len[x]=max(len[x],len[y]+1);
	sort(g[x].begin(),g[x].end(),[](int x,int y){return len[x]<len[y];});
}
void dfs2(int x){
	a[m++]=x;
	for(int y:g[x])dfs2(y);
}
void print(int x,bool nd){
	int lst=0,cnt=0;
	for(int y:g[x]){
		cnt++;
		for(int i=1;i<=lst;i++)cout<<y<<' ';
		print(y,nd&&cnt==g[x].size());
		lst=len[y];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<n;i++)scanf("%d",&x),g[x].push_back(i);
	dfs(0),dfs2(0);
	for(int i=0;i<m;i++)cout<<a[i]<<' ';
	puts(""),cout<<n-1-len[1]<<'\n';
	print(0,1);
}