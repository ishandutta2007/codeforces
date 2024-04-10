#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
bool vis[100001];
int p[100001];
int s;
vector<int>v;
void dfs(int id){
	s++;
	vis[id]=true;
	if(!vis[p[id]]) dfs(p[id]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
	}
	for(int i=1; i<=n ;i++){
		if(!vis[i]){
			s=0;
			dfs(i);
			v.push_back(s);
		}
	}
	sort(v.begin(),v.end());
	if(v.size()>=2){
		v[v.size()-2]+=v.back();
		v.pop_back();
	}
	long long ans=0;
	for(int i=0; i<v.size() ;i++){
		ans=ans+1LL*v[i]*v[i];
	}
	cout << ans << endl;
}