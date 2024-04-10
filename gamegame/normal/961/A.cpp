#include<iostream>
using namespace std;
int cnt[1001];
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int p;
		cin >> p;
		cnt[p]++;
	}
	int mini=1e9;
	for(int i=1; i<=n ;i++) mini=min(mini,cnt[i]);
	cout << mini << endl;
}