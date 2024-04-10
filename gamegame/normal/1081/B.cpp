#include<iostream>
#include<queue>
using namespace std;
vector<int>v[100001];
int n;
int ans[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;
		cin >> x;
		x=n-x;
		v[x].push_back(i);
		if(v[x].size()==x){
			for(auto cur:v[x]) ans[cur]=i;
			v[x].clear();
			v[x].shrink_to_fit();
		}
	}
	for(int i=1; i<=n ;i++){
		if(ans[i]==0){
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
	cout << endl;
}