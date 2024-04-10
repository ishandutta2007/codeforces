#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int p[100001];
vector<int>c[100001];
int q[100001];
int cur=0;
void dfs(int id){
	if(c[id].empty()) q[id]=1;
	for(auto cur:c[id]){
		dfs(cur);
		q[id]+=q[cur];
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=n ;i++){
		cin >> p[i];
		c[p[i]].push_back(i);
	}
	dfs(1);
	sort(q+1,q+n+1);
	for(int i=1; i<=n ;i++) cout << q[i] << ' ';
}