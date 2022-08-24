#include<bits/stdc++.h>
using namespace std;
int n,m;
bool t[300001];
vector<int>mx,my;
void solve(){
	cin >> n >> m;
	for(int i=1; i<=3*n ;i++) t[i]=false;
	mx.clear();my.clear();
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		if(!t[u] && !t[v]){
			mx.push_back(i);
			t[u]=t[v]=true;
		}
	}
	if(mx.size()>=n){
		cout << "Matching\n";
		for(int i=0; i<n ;i++) cout << mx[i] << ' ';
		cout << '\n';
	}
	else{
		cout << "IndSet\n";
		int cnt=0;
		for(int i=1; i<=3*n && cnt<n ;i++){
			if(!t[i]){
				cnt++;
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}