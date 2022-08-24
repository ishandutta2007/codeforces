#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m,k;
vector<int>c[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=n ;i++){
		int p;
		cin >> p;
		c[p].push_back(i);
	}
	for(int i=1; i<=n ;i++){
		if(c[i].empty()) continue;
		int cnt=0;
		for(int j=0; j<c[i].size() ;j++){
			if(c[c[i][j]].empty()) cnt++;
		}
		if(cnt<3){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}